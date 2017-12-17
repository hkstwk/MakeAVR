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

#define LED_PORT		PORTB
#define LED_DDR		DDRB
#define LED			PB1
#define LED0			PB0
#define SHREG_PORT	PORTD
#define	SHREG_DDR	DDRD
#define DATA			PD5
#define SHIFT		PD6
#define LATCH		PD7
#define BUTTON_PORT	PORTD
#define BUTTON_DDR	DDRD
#define BUTTON		PD2
#define DELAY		5 		// delay in milliseconds

#define DEBOUNCE_TIME 1000 // microseconds


#endif /* PINDEFINES_H_ */
