/*
 * c2_programming_avrs.h
 *
 *  Created on: 12 dec. 2017
 *      Author: harm
 */

#ifndef C2_PROGRAMMING_AVRS_H_
#define C2_PROGRAMMING_AVRS_H_

#include <avr/interrupt.h>

#define TIMER16					TCNT1
#define OUTPUT_COMP				OCR1A
#define TIMER_REGISTER_A 		TCCR1A
#define TIMER_REGISTER_B			TCCR1B
#define CTC_MODE					(1 << WGM12)
#define CLOCK_SELECT				(1 << CS11)
//#define CLOCK_SELECT				(1 << CS12) | (1 << CS10)
#define TIMER_INTERRUPT_MASK		TIMSK1
#define COMPARE_MATCH_INTERRUPT	(1 << OCIE1A)
#define OUTPUT_COMPARE			OCR1A

void blinkingLed();


#endif /* C2_PROGRAMMING_AVRS_H_ */
