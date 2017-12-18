/*
 * makeavr_util.h
 *
 *  Created on: 17 dec. 2017
 *      Author: harm
 */

#ifndef MAKEAVR_UTIL_H_
#define MAKEAVR_UTIL_H_

void clearLeds();
uint8_t debounce(uint8_t btn);
void initInterrupt1(void);
void ledInterrupt1Toggle();

#endif /* MAKEAVR_UTIL_H_ */
