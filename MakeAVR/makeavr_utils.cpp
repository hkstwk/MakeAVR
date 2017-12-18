/*
 * makeavr_utils.cpp
 *
 *  Created on: 17 dec. 2017
 *      Author: harm
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "makeavr_util.h"
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

void HC595Init(){
	// Set pins to output in order to control Shift Register
	HC595_DDR |= (1 << HC595_DATA) | (1 << HC595_SHIFT) | (1 << HC595_LATCH);
}

/* Shift data in by pulsing shift clock SH_CP */
void HC595Pulse(){
	HC595_PORT |=  (1 << HC595_SHIFT);
	_delay_ms(1);
	HC595_PORT &= ~(1 << HC595_SHIFT);
}

/* Send contents of shift register to storage (output)
 * by clocking ST_CP */
void HC595Latch(){
	HC595_PORT |=  (1 << HC595_LATCH);
	_delay_loop_1(1);
	HC595_PORT &= ~(1 << HC595_LATCH);
	_delay_loop_1(1);
}

/* Send in 8 bits serially. And then move them i nthe register one by one.
 * Once all 8 bits are done, pull the latch and set the bit on the output pins */
void HC595Write(uint8_t oneByte){
	HC595Init();
	for (uint8_t i =0; i<8; i++){
		//output data on DS according to MSB value
		if (oneByte & 0b10000000){
			HC595DataHigh();
		}
		else {
			HC595DataLow();
		}

		HC595Pulse(); // Shift bit in the register
		oneByte = (oneByte << 1);

	}

	/* Now all 8 bits are set in shift register
	 * Time to pull the latch and set the output pins
	 */
	HC595Latch();
}


