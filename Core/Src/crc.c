#include "../Inc/crc.h"


uint16_t CCITT_16(uint8_t* rx_buff, uint8_t len){

	uint16_t crc = 0x0000;

	for(int i = 0; i < len; i++){
		crc ^= ((uint16_t)rx_buff[i] << 8);

		for(int bit = 0; bit < 8; bit++){
			if(crc & 0x8000)
				crc = (crc << 1) ^ 0x1021;
			else
				crc = crc << 1;
		}
	}

	return crc;
}
