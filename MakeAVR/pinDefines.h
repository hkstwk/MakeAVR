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
#include "avr/interrupt.h"

#define LED_PORT		PORTB
#define LED_DDR		DDRB
#define LED			PB0
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

//#define TIMER16					TCNT1
//#define OUTPUT_COMP				OCR1A
//#define TIMER_REGISTER_A 		TCCR1A
//#define TIMER_REGISTER_B			TCCR1B
//#define CTC_MODE					(1 << WGM12)
//#define CLOCK_SELECT				(1 << CS11)
////#define CLOCK_SELECT				(1 << CS12) | (1 << CS10)
//#define TIMER_INTERRUPT_MASK		TIMSK1
//#define COMPARE_MATCH_INTERRUPT	(1 << OCIE1A)
//#define OUTPUT_COMPARE			OCR1A

#endif /* PINDEFINES_H_ */
