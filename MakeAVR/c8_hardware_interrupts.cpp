#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

ISR(INT0_vect){
	if (bit_is_clear(PIND,BUTTON)){
		LED_PORT |= (1 << LED);
	}
	else {
		LED_PORT &= ~(1 << LED);
	}
}

void initInterrupt0(void){
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC00) | (0 << ISC01);
	sei();
}

void ledInterruptToggle(){
	LED_DDR = 0xff;
	BUTTON_PORT |= (1 << BUTTON);
	initInterrupt0();

	while (1){
		_delay_ms(50);
		LED_PORT ^= (1 << LED0);
	}
}
