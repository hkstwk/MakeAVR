/*
 * animations.cpp
 *
 *  Created on: 11 dec. 2017
 *      Author: harm
 */
#include "pinDefines.h"
#include "makeavr_util.h"

extern volatile uint8_t animationIndexChanged;

void POVDisplay(uint8_t oneByte) {
	LED_PORT = oneByte;
	_delay_ms(DELAY);
}

void POVDisplayHC595(uint8_t oneByte) {
	HC595Write(oneByte);
	_delay_ms(DELAY);
}

void CountBinary(){
	while (1 & (animationIndexChanged == 0)){
		for (uint8_t i=0;i<=255;i++){
			/* break the for loop on INT1 interrupt */
			if (animationIndexChanged){
				break;
			}
			POVDisplayHC595(i);
			if (i == 255) {
				_delay_ms(DELAY);
			} else {
				_delay_us(1);
			}
		}
		_delay_ms(DELAY);
		LED_PORT = 0;
	}
}

void PovAnimate(){
	while (1 & (animationIndexChanged == 0)){
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

		_delay_ms(DELAY);
		LED_PORT = 0;
	}
}

void PovAnimateHC595(){
	while (1 & (animationIndexChanged == 0)){
		POVDisplayHC595(0b00001110);
		POVDisplayHC595(0b00011000);
		POVDisplayHC595(0b10111101);
		POVDisplayHC595(0b01110110);
		POVDisplayHC595(0b00111100);
		POVDisplayHC595(0b00111100);
		POVDisplayHC595(0b00111100);
		POVDisplayHC595(0b00111100);
		POVDisplayHC595(0b01110110);
		POVDisplayHC595(0b10111101);
		POVDisplayHC595(0b00011000);
		POVDisplayHC595(0b00001110);

		_delay_ms(DELAY);
		LED_PORT = 0;
	}
}



