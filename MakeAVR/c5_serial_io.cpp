/*
 * c6_serial_io.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: harm
 */
#include "pinDefines.h"
#include "USART.h"


void serialLoopback(){
	char serialCharacter;

	LED_DDR = 0xff;
	initUSART();
	printString("Hello World!\r\n");

	while (1){
		serialCharacter = receiveByte();
		transmitByte(serialCharacter);
		LED_PORT = serialCharacter;
	}
}



