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

#include"config.h"

uint32_t calc_buffer_checksum(const uint8_t *buffer,uint32_t len_bytes){
	uint32_t len_32=(len_bytes-1)/4+1;
	uint32_t sum=0;
	uint32_t len_do_32=(len_32-1);
	for(int i=0;i<len_do_32;i++){
		sum+=*(uint32_t *)&buffer[4*i];
	}
	if(len_do_32*4<len_bytes){
		uint8_t bytes[4];
		for(int b=0;b<4;b++){bytes[b]=0;}
		for(int b=len_do_32*4,bb=0;b<len_bytes&&bb<4;b++,bb++){
			bytes[bb]=buffer[b];
		}
		sum+=*(uint32_t *)&bytes[0];
	}
	return sum;
}

