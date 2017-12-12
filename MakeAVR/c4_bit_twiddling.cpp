/*
 * c4_bit_twiddling.cpp
 *
 *  Created on: 11 dec. 2017
 *      Author: harm
 */
#include "pinDefines.h"

void clearLeds(){
	LED_PORT = 0x00;
	_delay_ms(DELAY);
}

void cyclonEyes(){
	uint8_t i = 0;
	while (i < 7){
		LED_PORT = (1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT = (1 << i);
		_delay_ms(DELAY);
		i--;
	}
	LED_PORT = (0 << 0);
}

void cyclonEyesOr(){
	uint8_t i = 0;
	while (i <= 7){
		LED_PORT |= (1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT &= ~(1 << i);
		_delay_ms(DELAY);
		i--;
	}
	clearLeds();
}

void cyclonEyesInverted(){
	uint8_t i = 0;
	while (i < 7){
		LED_PORT = ~(1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT = ~(1 << i);
		_delay_ms(DELAY);
		i--;
	}
	clearLeds();
}


