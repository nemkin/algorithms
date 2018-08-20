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


#include"udp_kliens.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("usage: %s port_to_listen\n",argv[0]);
		exit(-1);
	}
	uint32_t udp_port_to_listen=atoi(argv[1]);

	const char window_name[]="camera_image";
	cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	
	init_car_interface(udp_port_to_listen);

	bool exit=false;
    int32_t last_frame_idx=-2;

    double road_wheel_angle=0.0;

    std::clock_t last_cycle = clock();
    std::clock_t last_udp = clock();
    double udp_period_time_ms = 50;
    bool brake_released=false;

    bool brake=true;
	do{
		image_header img_header;
		car_state_str state;
		
		get_curr_image_header(&img_header);
        if(int32_t(img_header.frame_idx)>last_frame_idx){
			last_frame_idx=img_header.frame_idx;
			copy_curr_car_state(&state);

            if(state.state_is_valid){
                cout<<"GPS:N"<<state.GPS_north_meter<<endl;
                cout<<"GPS:E"<<state.GPS_east_meter<<endl;
                cout<<"VEL"<<state.velocity_km_per_h<<endl;
            }

            if(img_header.size_sx>0){
                bool use_cpp_and_opencv=true;
                if(use_cpp_and_opencv){
                    cv::Mat img;
                    copy_curr_image_to_cvMat(img);

                    cv::imshow(window_name,img);
                }else{
                    //alloc buffer
                    //void copy_curr_image_to_buffer(uint8_t *p_buffer,uint32_t buffer_allocated_len);
                }
            }
        }

        uint32_t keycode=cv::waitKey(50);
        uint8_t key8=toupper(keycode&0xff);
       // cout<<key8<<endl;
        if(key8==27){
            exit=true;
        }
        if(key8=='W'){
            brake=false;
        }
        if(key8=='S'){
            brake=true;
            road_wheel_angle=0.0;
        }
        if(key8==' '){
            road_wheel_angle=0.0;
        }
        if(key8=='A'){
            road_wheel_angle-=10;
        }
        if(key8=='D'){
            road_wheel_angle+=10;
        }
        send_drive_signals(int(road_wheel_angle),!brake);//TODO: implement

	}while(!exit);

	close_car_interface();
	return 0;
	
}
