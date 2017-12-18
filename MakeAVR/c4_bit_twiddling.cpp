/*
 * c4_bit_twiddling.cpp
 *
 *  Created on: 12 dec. 2017
 *      Author: harm
 */

#ifndef C4_BIT_TWIDDLING_CPP_
#define C4_BIT_TWIDDLING_CPP_

#include "pinDefines.h"

extern volatile uint8_t animationIndexChanged;

void clearLeds(){
	LED_PORT = 0x00;
	_delay_ms(DELAY);
}

void cyclonEyes(){
	while (1) {
		uint8_t i = 0;
		if (animationIndexChanged){
			break;
		}
		while ((i < 7) & (animationIndexChanged == 0)){
			LED_PORT = (1 << i);
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			LED_PORT = (1 << i);
			_delay_ms(DELAY);
			i--;
		}
		LED_PORT = (0 << 0);
	}
}

void cyclonEyesOr(){
	while (1){
		uint8_t i = 0;
		if (animationIndexChanged){
			break;
		}
		while ((i <= 7) & (animationIndexChanged == 0)){
			LED_PORT |= (1 << i);
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			LED_PORT &= ~(1 << i);
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
			LED_PORT = ~(1 << i);
			_delay_ms(DELAY);
			i++;
		}
		while ((i < 255) & (animationIndexChanged == 0)){
			LED_PORT = ~(1 << i);
			_delay_ms(DELAY);
			i--;
		}
	}
}

#endif /* C4_BIT_TWIDDLING_CPP_ */
