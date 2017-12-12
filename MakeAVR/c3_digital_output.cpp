/*
 * animations.cpp
 *
 *  Created on: 11 dec. 2017
 *      Author: harm
 */
#include "pinDefines.h"

void POVDisplay(uint8_t oneByte) {
	LED_PORT = oneByte;
	_delay_ms(10);
}

void CountBinary(){
	for (uint8_t i=0;i<=255;i++){
		POVDisplay(i);
		if (i == 255) {
			_delay_ms(2000);
		} else {
			_delay_us(1);
		}
	}
}

void PovAnimate(){
	POVDisplay(0b00001110);
	POVDisplay(0b00011000);
	POVDisplay(0b10111101);
	POVDisplay(0b01110110);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b01110110);
	POVDisplay(0b10111101);
	POVDisplay(0b00011000);
	POVDisplay(0b00001110);

	LED_PORT = 0;
	_delay_ms(DELAY);
}


