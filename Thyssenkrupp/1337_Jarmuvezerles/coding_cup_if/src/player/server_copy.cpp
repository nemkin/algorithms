/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "../PracticalSocket.h" // For UDPSocket and SocketException
#include <cstdlib>           // For atoi()
#include <ctime>
#include <iostream>          // For cout and cerr
#include <thread>
#include <cstring>
#include <vector>
#include <inttypes.h>

using namespace std;
#include "../config.h"


enum server_mode{
	real_time=0,
	save=1,
	playback=2
};


server_mode MODE;

struct udp_packs_file_header{
	uint32_t file_version;//=1
	uint32_t pack_size_bytes;//=PACK_SIZE
};


//N_frames* (N_frames not saved, it is determined if end of file reached

struct udp_packs_frame_header{
	uint32_t frame_idx;//increasing from 0
	uint32_t clock_ms;//relative to first saved frame
	uint32_t full_length_bytes;//of this frame, including this header
	uint32_t n_total_pack;//saved redundantly
};

//n_tatalpack *
struct udp_packs_onepack{
	uint32_t length_in_bytes;
	uint8_t data[PACK_SIZE];
};
//of the above,  one is saved with 4 bytes, and n_total_pack repeated
//then n_total_pack is saved.


int main(int argc, char *argv[]) {
	MODE=server_mode::real_time;
//	MODE=server_mode::save;
//	MODE=server_mode::playback;
#ifdef UDP_SERVER_MODE_PLAYBACK
        MODE=server_mode::playback;
#endif

	bool need_UDP=MODE==save?false:true;
	bool need_SHM_and_IMPROC=MODE==playback?false:true;
	bool need_FILE=MODE==real_time?false:true;

	string         servAddress;
	unsigned short servPort;
	if(need_UDP){
#ifdef UDP_SERVER_MODE_PLAYBACK
        if ((argc!=4)) { // Test for correct number of arguments
            cout << "Usage: " << argv[0] << " <Klient Machine IP Address> <Kliens Port> filename_to_playback\n";
            exit(1);
		}
#else
#endif
		servAddress = argv[1]; // First arg: server address
		servPort    = Socket::resolveService(argv[2], "udp");
	}
	time_t rawtime;
	struct tm* timeinfo;
    char filename_str[800];
	time(&rawtime);
	timeinfo=localtime(&rawtime);


	if(need_FILE){	cout<< "FILENAME  "<<filename_str<<""<<endl;}
	uint32_t frame_idx=0;
	FILE* file_ptr=nullptr;

	udp_packs_onepack one_pack;
	udp_packs_frame_header fr_head;
	udp_packs_file_header f_head;
	if(need_FILE){
		if(MODE==save    ){
			strftime(filename_str,sizeof(filename_str),"playback/%Y-%m-%d_%I:%M:%S.bin",timeinfo);
			file_ptr=fopen(filename_str,"wb");
		}
		if(MODE==playback){
            //			strncpy(filename_str,"playback/test_vid1.bin",sizeof(filename_str));
            strncpy(filename_str,argv[3],sizeof(filename_str));
            file_ptr=fopen(filename_str,"rb");
		}
		if(file_ptr==nullptr){
			cout<< "FILE PTR NULL, CAN NOT OPEN FILE:"<<filename_str<<endl;
			exit(1);
		}
		if(MODE==save){
			f_head.file_version=1;
			f_head.pack_size_bytes=PACK_SIZE;
			fwrite(&f_head,sizeof(udp_packs_file_header),1,file_ptr);
			fclose(file_ptr);file_ptr=nullptr;
		}
		if(MODE==playback){
			int ptr_in_file=0;
			size_t res = fread(&f_head,sizeof(udp_packs_file_header),1,file_ptr);
			ptr_in_file=sizeof(udp_packs_file_header);
			cout << "PTR_IN_FILE " << ptr_in_file <<endl;
			cout << "SIZE_T " << res <<endl;
			cout << "PACKSIZE " << f_head.pack_size_bytes <<endl;
			if(f_head.pack_size_bytes != PACK_SIZE){
				cerr << "PACK_SIZE mismatch" <<endl;
				exit(1);
			}
		}
	}//if need_FILE

	try {
		UDPSocket sock;
		int       jpegqual = ENCODE_QUALITY; // Compression Parameter

        vector<uint8_t> encoded;
        const char window_name[]="shm_udp_server:image_to_send";

//		Mat image;
//		image = imread("lena_orig.jpg", CV_LOAD_IMAGE_COLOR);

		std::clock_t last_cycle = clock();
		std::clock_t first_frame_ms = clock();
		int loop_idx=-2;
		int N_cams=-1;
		int idx_fwd_left = -1;

		double car_state_bufer[(PACK_SIZE*ADDITIONAL_PACKS_NUM)/sizeof(double)];


		cout << "Before while";
		uint32_t image_checksum_32=0;
		uint32_t compressed_checksum_32=0;

		while (1) {
			if(MODE==save){
				file_ptr=fopen(filename_str,"ab+");
			}
			int total_pack=-1;
            if(need_SHM_and_IMPROC){
			}else{ // if need_SHM_and_IMPROC
				//playback:
				size_t res = fread(&fr_head,sizeof(fr_head),1,file_ptr);
				if(res!=1){
					cout<< "END OF FILE"<<endl;
					fclose(file_ptr);file_ptr=nullptr;
					exit(1);
				}
				total_pack=fr_head.n_total_pack;
			}//else need_SHM_and_IMPROC
			if(MODE==save){
				if(frame_idx>0){
					fr_head.clock_ms=clock()-first_frame_ms;
				}else{
					first_frame_ms = clock();
					fr_head.clock_ms=0;
					cout << "fr_IDX " << fr_head.frame_idx <<endl;
				}
				fr_head.frame_idx = frame_idx;
				fr_head.full_length_bytes = (total_pack+1)*sizeof(udp_packs_onepack)+sizeof(fr_head); // TODO calculate frame_length
				fr_head.n_total_pack = uint32_t(total_pack);
				cout << "N_TOTAL_PACK " << fr_head.n_total_pack <<endl;
				fwrite(&fr_head,sizeof(fr_head),1,file_ptr);
				//fclose(file_ptr);file_ptr=nullptr;
			}


			int32_t ibuf[1];
			ibuf[0] = total_pack;
			if(need_UDP){
				if(MODE==playback){
					int res = fread(&one_pack,sizeof(one_pack),1,file_ptr);
				}
				sock.sendTo(ibuf, sizeof(ibuf), servAddress, servPort);
				using namespace std::chrono_literals;
				std::this_thread::sleep_for(1000ns*(1.0/double(PLANNED_BAUD_RATE_Mbitps))*PACK_SIZE*8);//20 ns: 50Mbit/sec baud rate
			}
			if(MODE==save){
				one_pack.length_in_bytes=sizeof(ibuf); //TODO Calculate length in bytes
				memcpy(&one_pack.data,ibuf,std::min(sizeof(ibuf),sizeof(one_pack.data)));
				fwrite(&one_pack,sizeof(one_pack),1,file_ptr);
			}
			int N_uAB=-1;
			if(need_SHM_and_IMPROC){
			}

			for (int ii = 0; ii < total_pack; ii++) {
				const void *p_packet_data=nullptr;
				if(need_SHM_and_IMPROC){
				}else{//
					//playback:
					int res = fread(&one_pack,sizeof(one_pack),1,file_ptr);
					p_packet_data=&one_pack.data[0];
					if(ii==0){
						comm_header CH;
						double uab_buffer[CAR_STATE_MSG_uAB_DOUBLES];
						memcpy(&CH,&one_pack.data[0],sizeof(CH));
						memcpy(&uab_buffer,&one_pack.data[sizeof(comm_header)],sizeof(double)*CAR_STATE_MSG_uAB_DOUBLES);
						if(CH.N_uAB>0){
							cout<<"N_uAB>0\n";
//							memcpy(CURR_CAR_STATE,uab_buffer,std::min(sizeof(CURR_CAR_STATE),sizeof(uab_buffer)));
						}

					}
				}
				if(need_UDP){
					using namespace std::chrono_literals;
					std::this_thread::sleep_for(1000ns*(1.0/double(PLANNED_BAUD_RATE_Mbitps))*PACK_SIZE*8);//20 ns: 50Mbit/sec baud rate
					sock.sendTo(p_packet_data, PACK_SIZE, servAddress, servPort);
				}

				if(MODE==save){
					one_pack.length_in_bytes=PACK_SIZE; //TODO Calculate length in bytes
					memcpy(&one_pack.data,p_packet_data,std::min(size_t(PACK_SIZE),sizeof(one_pack.data)));
					fwrite(&one_pack,sizeof(one_pack),1,file_ptr);
				}
			}

			std::clock_t next_cycle = clock();
			double       duration   = (next_cycle - last_cycle) / (double)CLOCKS_PER_SEC;
			cout << "\teffective FPS:" << (1 / duration) << " \tkbps:" << (PACK_SIZE * total_pack / duration / 1024 * 8) << endl;

			cout << next_cycle - last_cycle;
			last_cycle = next_cycle;
//start of merged RT+playback:
			frame_idx++;
			if(MODE==save){
				fclose(file_ptr);file_ptr=nullptr;
			}

			if(need_SHM_and_IMPROC)
			{
			}else{
				using namespace std::chrono_literals;
				std::this_thread::sleep_for(1ms*FRAME_INTERVAL_ms);
			}
		}//while 1
	} catch (SocketException &e) {
		cerr << e.what() << endl;
		if(file_ptr!=nullptr){
			fclose(file_ptr);
		}
		exit(1);
	}
	if(file_ptr!=nullptr){fclose(file_ptr);file_ptr=nullptr;}

   cout<< "EXITING"<<endl;
   exit(1);


//end of saver
   return 0;
}
