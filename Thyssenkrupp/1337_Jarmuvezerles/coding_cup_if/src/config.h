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
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include<inttypes.h>

#define FRAME_WIDTH 800 //800
#define FRAME_HEIGHT 288 //288
#define FRAME_INTERVAL_ms (1000/10)
#define PLANNED_BAUD_RATE_Mbitps 50
#define PACK_SIZE 1024 //udp pack size; note that OSX limits < 8100 bytes
const double COMM_VERSION_FORMAT=2004.0;
struct comm_header{
   double comm_version;//=COMM_VERSION_FORMAT;
   double header_length_total;
   double image_checksum_32;//simple 32 bit add of 4 bytes, in x86 endianness
   double compressed_checksum_32;
   double image_sx;
   double image_sy;
   double image_pixelsize_bytes;
   double encoded_length_bytes;
   double N_uAB;
   double uAB_msg_doubles;
};
const int CAR_STATE_MSG_HEADER_DOUBLES=sizeof(comm_header)/sizeof(double);
const int CAR_STATE_MSG_uAB_DOUBLES= (28); //double comm_version double n_uAB_msgs (double) + 28 double
const int CAR_STATE_MSG_DOUBLES= (CAR_STATE_MSG_HEADER_DOUBLES+CAR_STATE_MSG_uAB_DOUBLES);
const int CAR_STATE_MSG_SIZE_BYTES= (sizeof(double)*CAR_STATE_MSG_DOUBLES);
const int ADDITIONAL_PACKS_NUM= (((CAR_STATE_MSG_SIZE_BYTES-1)/PACK_SIZE)+1);
const int ENCODE_QUALITY= 85;
const int CAM_LEFT_SERIAL= 22372946; //cam left in Mercedes
//const int CAM_LEFT_SERIAL= 21971758; //cam left in Fiesta
//const int CAM_LEFT_SERIAL= 22372953; //cam left in Office

uint32_t calc_buffer_checksum(const uint8_t *buffer,uint32_t len_bytes);

#endif
