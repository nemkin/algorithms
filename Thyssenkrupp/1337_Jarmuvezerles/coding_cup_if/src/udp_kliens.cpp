#include"udp_kliens.h"

/*
 *
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


#include "PracticalSocket.h" // For UDPSocket and SocketException
#include <cstdlib>           // For atoi()
#include <ctime>
#include <iostream>          // For cout and cerr
#include <thread>

#define BUF_LEN 65540        // Larger than maximum UDP packet size

#include "opencv2/opencv.hpp"
#include "config.h"

struct KLIENS_VARS{
   UDPSocket sock;
   UDPSocket sock_uAB;
   std::clock_t last_cycle = clock();
   std::clock_t last_udp = clock();

   char           buffer[BUF_LEN]; // Buffer for echo string
   int            recvMsgSize;     // Size of received message
   string         sourceAddress;   // Address of datagram source
   unsigned short sourcePort;      // Port of datagram source

   unsigned short servPort_uAB;
   string servAddress_uAB;

   unsigned short should_send_udp = 0;
   double udp_period_time = 100;

   comm_header CH;
   double uab_buffer[CAR_STATE_MSG_uAB_DOUBLES];
   cv::Mat frame;
   bool go;

   thread thread2;

   image_header CURR_IMG_HEADER;
   car_state_str CURR_CAR_STATE;

   uint32_t frame_idx;
};

KLIENS_VARS GLOB;

void get_curr_image_header(image_header *p_img_head){
   *p_img_head=GLOB.CURR_IMG_HEADER;
}
void copy_curr_car_state(car_state_str *p_car_state){
   *p_car_state=GLOB.CURR_CAR_STATE;
}
//void copy_curr_image_to_buffer(uint8_t *p_buffer,uint32_t buffer_allocated_len);
void copy_curr_image_to_cvMat(cv::Mat &dst){
   dst=GLOB.frame;
}

void send_drive_signals(int angle, bool brk_rlsd){
    double dub_angle = angle/480.0*32768.0;
    //cout<<dub_angle<<endl;
    int ang = int(dub_angle);
    //cout<<ang<<endl;
    if(ang>32767){
        ang=32767;
    }
    if(ang<-32767){
        ang=-32767;
    }
    uint16_t ibuf[4];
    ibuf[0] = ang;
    ibuf[1] = 0;
    ibuf[2] = 0;
    ibuf[3] = 0;
    if(brk_rlsd){
        ibuf[2] = 0xFF;
        ibuf[3] = 0xFF;
    }
    try{
        GLOB.sock_uAB.sendTo(ibuf, sizeof(ibuf), GLOB.servAddress_uAB, GLOB.servPort_uAB);
    } catch (SocketException &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

void thread_listen();

void init_car_interface(uint32_t udp_port_to_listen){

	try {
		GLOB.sock.setLocalPort((unsigned short)(udp_port_to_listen));
		//UDPSocket sock(unsigned short(udp_port_to_listen));

        GLOB.servPort_uAB = Socket::resolveService("5001", "udp");
        GLOB.servAddress_uAB = "192.168.5.31";

		GLOB.last_cycle = clock();
		GLOB.last_udp = clock();
	} catch (SocketException &e) {
		cerr << e.what() << endl;
		exit(1);
	}

	GLOB.thread2=thread(thread_listen);
}

void close_car_interface(){
	GLOB.go=false;
	GLOB.thread2.join();
}


void thread_listen(){
      GLOB.go=true;
      GLOB.frame_idx=0;
      while (GLOB.go) {
         try{
         // Block until receive message from a client
         bool transfer_is_ok_up_to_now=false;

			do {
				GLOB.recvMsgSize = GLOB.sock.recvFrom(GLOB.buffer, BUF_LEN, GLOB.sourceAddress, GLOB.sourcePort);
			} while (GLOB.recvMsgSize > sizeof(int));
			int total_pack = ((int *)GLOB.buffer)[0];

			transfer_is_ok_up_to_now=true;
            //cout << "expecting length of packs:" << total_pack << endl;
			//char *longbuf = new char[PACK_SIZE * total_pack];
			std::vector<uint8_t> longbuff(size_t(PACK_SIZE * total_pack));

			for (int ii = 0; ii < total_pack; ii++) {
				GLOB.recvMsgSize = GLOB.sock.recvFrom(GLOB.buffer, BUF_LEN, GLOB.sourceAddress, GLOB.sourcePort);

				if (GLOB.recvMsgSize != PACK_SIZE) {
					cerr << "Received unexpected size pack:" << GLOB.recvMsgSize << endl;
					transfer_is_ok_up_to_now=false;
					continue;
				}
				if(ii<ADDITIONAL_PACKS_NUM){
				  //uAB mesg
				  memcpy(&GLOB.CH,GLOB.buffer,sizeof(GLOB.CH));
				  memcpy(&GLOB.uab_buffer,&GLOB.buffer[sizeof(comm_header)],sizeof(double)*CAR_STATE_MSG_uAB_DOUBLES);
				  if(GLOB.CH.N_uAB>0){
                      //memcpy(&GLOB.CURR_CAR_STATE,&GLOB.uab_buffer,std::min(sizeof(GLOB.CURR_CAR_STATE),sizeof(GLOB.uab_buffer)));
                      GLOB.CURR_CAR_STATE.massage_counter               =GLOB.uab_buffer[ 4];
                      GLOB.CURR_CAR_STATE.velocity_km_per_h             =GLOB.uab_buffer[ 5];
                      GLOB.CURR_CAR_STATE.GPS_east_meter                =GLOB.uab_buffer[ 6];
                      GLOB.CURR_CAR_STATE.GPS_north_meter               =GLOB.uab_buffer[ 7];
                      GLOB.CURR_CAR_STATE.Yaw_rate_degree_per_sec       =GLOB.uab_buffer[ 9];
                      GLOB.CURR_CAR_STATE.forward_acceleration_m_per_s2 =GLOB.uab_buffer[10];
                      GLOB.CURR_CAR_STATE.left_acceleration_m_per_s2    =GLOB.uab_buffer[11];
                      GLOB.CURR_CAR_STATE.state_is_valid=true;
                  }else{
                      GLOB.CURR_CAR_STATE.state_is_valid=false;
                  }

				}else{
				  int i=ii-ADDITIONAL_PACKS_NUM;
				  memcpy(&longbuff[i * PACK_SIZE], GLOB.buffer, PACK_SIZE);
				}
			}
			if(transfer_is_ok_up_to_now){
				if((total_pack-ADDITIONAL_PACKS_NUM)*PACK_SIZE>=GLOB.CH.encoded_length_bytes){
				}else{
					transfer_is_ok_up_to_now=false;
				}
			}

         if(transfer_is_ok_up_to_now){
            //cout << "cntr- " << GLOB.uab_buffer[4] << endl;
            //cout << "veh_sp- " << GLOB.uab_buffer[5] << endl;
            //cout << "x_east- " << GLOB.uab_buffer[6] << endl;
            //cout << "y_north- " << GLOB.uab_buffer[7] << endl;
            //cout << "yaw- " << GLOB.uab_buffer[9] << endl;
            //cout << "long_acc- " << GLOB.uab_buffer[10] << endl;
            //cout << "lat_acc- " << GLOB.uab_buffer[11] << endl;
            //cout << "nAB- " << GLOB.CH.N_uAB << endl;
            //cout << "Received" << total_pack << " packets from " << sourceAddress << ":" << sourcePort << endl;

            uint32_t checksum_encoded_32=calc_buffer_checksum(longbuff.data(),uint32_t(GLOB.CH.encoded_length_bytes));

            if(checksum_encoded_32==uint32_t(GLOB.CH.compressed_checksum_32)){

					cv::Mat rawData = cv::Mat(1, PACK_SIZE * total_pack-ADDITIONAL_PACKS_NUM, CV_8UC1, longbuff.data());
					cv::Mat frame_   = imdecode(rawData, CV_LOAD_IMAGE_COLOR);

					bool frame_is_ok=true;
					uint32_t image_checksum_32=0;
					uint32_t sx=uint32_t(frame_.cols);
					uint32_t sy=uint32_t(frame_.rows);
                    if(sx!=uint32_t(GLOB.CH.image_sx)){frame_is_ok=false;cerr<<"decompressed image sizeX is bad!\n";}
                    if(sy!=uint32_t(GLOB.CH.image_sy)){frame_is_ok=false;cerr<<"decompressed image sizeY is bad!\n";}
                    if(frame_.elemSize()!=uint32_t(GLOB.CH.image_pixelsize_bytes)){frame_is_ok=false;cerr<<"pixel size in bytes is bad!\n";}
					if(frame_is_ok){
						for(int y=0;y<sy;y++){
							uint8_t *p_row=frame_.ptr(y);
							uint len=frame_.elemSize()*sx;
							image_checksum_32+=calc_buffer_checksum(p_row,len);
						}
                        //if(image_checksum_32!=uint32_t(GLOB.CH.image_checksum_32)){frame_is_ok=false;cerr<<"decompressed image checksum is bad!\n";}
					}


					if (frame_.size().width == 0) {
						cerr << "decode failure!" << endl;
						frame_is_ok=false;
					}
					if(frame_is_ok){
						GLOB.frame=frame_;
						GLOB.CURR_IMG_HEADER.frame_idx=GLOB.frame_idx;
						GLOB.frame_idx++;
						GLOB.CURR_IMG_HEADER.num_channels=frame_.elemSize()/frame_.elemSize1();
						GLOB.CURR_IMG_HEADER.image_size_bytes=frame_.dataend-frame_.data;
						GLOB.CURR_IMG_HEADER.row_step_in_bytes=frame_.step1();
						GLOB.CURR_IMG_HEADER.size_sx=frame_.cols;
						GLOB.CURR_IMG_HEADER.size_sy=frame_.rows;
					}
//					imshow("recv", frame);
				}else{
                    cerr<<"compressed data checksum is bad!\n";
				}
			}

            //cv::waitKey(1);
			clock_t next_cycle = clock();
			double  duration   = (next_cycle - GLOB.last_cycle) / (double)CLOCKS_PER_SEC;
				//cout << "\teffective FPS:" << (1 / duration) << " \tkbps:" << (PACK_SIZE * total_pack / duration / 1024 * 8) << endl;

            //cout << next_cycle - GLOB.last_cycle;
			GLOB.last_cycle = next_cycle;

			} catch (SocketException &e) {
				cerr << e.what() << endl;
				exit(1);
			}

		}

//	return 0;
}
