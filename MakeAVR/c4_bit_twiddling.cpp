/*
 * c4_bit_twiddling.cpp
 *
 *  Created on: 12 dec. 2017
 *      Author: harm
 */

#ifndef C4_BIT_TWIDDLING_CPP_
#define C4_BIT_TWIDDLING_CPP_

#include "pinDefines.h"
#include "makeavr_util.h"

extern volatile uint8_t animationIndexChanged;

void cyclonEyes(){
	while (1) {
		uint8_t i = 0;
		if (animationIndexChanged){
			break;
		}
		while ((i < 7) & (animationIndexChanged == 0)){
			HC595Write((1<<i));
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			HC595Write((1<<i));
			_delay_ms(DELAY);
			i--;
		}
		LED_PORT = (0 << 0);
	}
}

void cyclonEyesOr(){
	while (1){
		uint8_t i = 0;
		uint8_t leds = 0x00;
		if (animationIndexChanged){
			break;
		}
		while ((i <= 7) & (animationIndexChanged == 0)){
			HC595Write(leds |= (1<<i));
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			HC595Write(leds &= (~(1<<i)));
			_delay_ms(DELAY);
			i--;
		}
		clearLeds();
	}
}

void cyclonEyesInverted(){
	while (1) {
		uint8_t i = 0;
		if (animationIndexChanged){
			break;
		}
		while ((i < 7) & (animationIndexChanged == 0)){
			HC595Write(~(1<<i));
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			HC595Write(~(1<<i));
			_delay_ms(DELAY);
			i--;
		}
	}
}

#endif /* C4_BIT_TWIDDLING_CPP_ */
