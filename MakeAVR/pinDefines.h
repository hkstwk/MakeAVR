/*
 * pinDefines.h
 *
 *  Created on: 11 dec. 2017
 *      Author: harm
 */

#ifndef PINDEFINES_H_
#define PINDEFINES_H_


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define ANIMATION_CNT	12
#define SWITCH_PORT	PORTC
#define SWITCH_DDR	DDRC
#define SWITCH_PIN	PC0
#define LED_PORT		PORTB
#define LED_DDR		DDRB
#define LED			PB1
#define LED0			PB0
#define LED2			PB2
#define LED3			PB3
#define BUTTON_PORT	PORTD
#define BUTTON_DDR	DDRD
#define BUTTON		PD2
#define BUTTON_TGL	PD3
#define DELAY		5 		// delay in milliseconds

#define DEBOUNCE_TIME 1000 // microseconds


#endif /* PINDEFINES_H_ */
