/*
 * makeavr_util.h
 *
 *  Created on: 17 dec. 2017
 *      Author: harm
 */

#ifndef MAKEAVR_UTIL_H_
#define MAKEAVR_UTIL_H_

#define HC595_PORT		PORTD
#define	HC595_DDR		DDRD
#define HC595_DATA		PD5
#define HC595_SHIFT		PD6
#define HC595_LATCH		PD7

#define HC595DataHigh()	(HC595_PORT |=  (1 << HC595_DATA));
#define HC595DataLow()	(HC595_PORT &= ~(1 << HC595_DATA));

void clearLeds();
uint8_t debounce(uint8_t btn);
void initInterrupt1(void);
void ledInterrupt1Toggle();
void HC595Write(uint8_t oneByte);

#endif /* MAKEAVR_UTIL_H_ */
