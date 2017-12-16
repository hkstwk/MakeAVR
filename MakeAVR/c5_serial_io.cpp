/*
 * c6_serial_io.cpp
 *
 *  Created on: 14 dec. 2017
 *      Author: harm
 */
#include "pinDefines.h"
#include "USART.h"
#include "c5_serial_io.h"


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

void testSerial(){
	UBRR0H = (BRC >> 8);
	UBRR0L =  BRC;

	UCSR0B = (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

	while (1){
		UDR0 = 'Q';
		_delay_ms(50);
	}
}


