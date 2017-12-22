/*
 * c14_switches.cpp
 *
 *  Created on: 21 dec. 2017
 *      Author: harm
 */

#include "pinDefines.h"
#include <avr/delay.h>

extern volatile uint8_t animationIndexChanged;

void switchLedsOnOff(){
	SWITCH_PORT &= 0x00;
	BUTTON_PORT = (1 << BUTTON) | (1 << BUTTON_TGL);
	SWITCH_DDR |= (1 << SWITCH_PIN);
	LED_DDR = 0xff;
	LED_PORT |= 0b11111111;

	while (1){
		if (animationIndexChanged){
			break;
		}
		SWITCH_PORT ^= (1 << SWITCH_PIN);
		_delay_ms(DELAY);
	}
}


