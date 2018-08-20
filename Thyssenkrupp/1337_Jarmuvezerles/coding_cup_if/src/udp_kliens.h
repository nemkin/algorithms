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

#ifndef UDP_KLIENS_H_INCLUDED
#define UDP_KLIENS_H_INCLUDED
#include<inttypes.h>
#include "opencv2/opencv.hpp"

struct image_header{
	uint32_t frame_idx;//increase of this signals if new frame arrived
	uint32_t size_sx;
	uint32_t size_sy;
	uint32_t num_channels;//3:r,g,b   4:r,g,b,alpha 1:intensity
	uint32_t row_step_in_bytes;//length of one image row with padding
	uint32_t image_size_bytes;
};

struct car_state_str{
    bool state_is_valid;
    double massage_counter; // ;-}
    double velocity_km_per_h;
    double GPS_east_meter;
    double GPS_north_meter;
    double Yaw_rate_degree_per_sec;
    double forward_acceleration_m_per_s2;
    double left_acceleration_m_per_s2;
};

	void init_car_interface(uint32_t udp_port_to_listen);
	
	void get_curr_image_header(image_header *p_img_head);
	void copy_curr_car_state(car_state_str *p_car_state);
	void copy_curr_image_to_buffer(uint8_t *p_buffer,uint32_t buffer_allocated_len);
	void copy_curr_image_to_cvMat(cv::Mat &dst);

    void send_drive_signals(int angle, bool brk_rlsd=false);
	
	
	void close_car_interface();
	

#endif
