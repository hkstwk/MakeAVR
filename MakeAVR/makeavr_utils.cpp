/*
 * makeavr_utils.cpp
 *
 *  Created on: 17 dec. 2017
 *      Author: harm
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

extern volatile uint8_t animationIndex;
extern volatile uint8_t animationIndexChanged;

void clearLeds(){
	LED_PORT = 0x00;
	_delay_ms(DELAY);
}

uint8_t debounce(uint8_t btn){
	if (!(PIND & (1 << btn))){       /* button is pressed */
		_delay_us(DEBOUNCE_TIME);
		if (!(PIND & (1 << btn))){   /* button is still pressed */
			return (1);
		}
	}
	return (0);
}

ISR(INT1_vect){
	if (debounce(BUTTON_TGL)) {
		if (bit_is_clear(PIND,BUTTON_TGL)){
			LED_PORT |= (1 << LED2);
			if (animationIndex < (ANIMATION_CNT-1)){
				animationIndex++;
			}
			else {
				animationIndex = 0;
			}
			animationIndexChanged = 1;
		}
		else {
			LED_PORT &= ~(1 << LED2);
		}
	}
}

void initInterrupt1(void){
	EIMSK |= (1 << INT1);
	EICRA |= (1 << ISC10) | (0 << ISC11);
	sei();
}

void ledInterrupt1Toggle(){
	LED_DDR = 0xff;
	BUTTON_PORT |= (1 << BUTTON_TGL);
	initInterrupt1();

	while (1){
		_delay_ms(50);
		LED_PORT ^= (1 << LED3);
	}
}



