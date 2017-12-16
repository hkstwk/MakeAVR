/*
 * c5_serial_io.h
 *
 *  Created on: 14 dec. 2017
 *      Author: harm
 */

#ifndef C5_SERIAL_IO_H_
#define C5_SERIAL_IO_H_

#define F_CPU 	2000000
#define BAUD	  	9600
#define BRC		((F_CPU/16/BAUD)-1)

void serialLoopback();
void testSerial();

#endif /* C5_SERIAL_IO_H_ */
