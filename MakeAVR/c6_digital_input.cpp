/*
 * c6_digital_input.cpp
 *
 *  Created on: 12 dec. 2017
 *      Author: harm
 */

#include "pinDefines.h"
#include "makeavr_util.h"
#include "c6_digital_input.h"

extern volatile uint8_t animationIndexChanged;

void toggleButton(){
	uint8_t buttonWasPressed = 0;
    BUTTON_DDR &= ~(1 << BUTTON); // Set button pin to input by clearing the bit. Safety precaution
    BUTTON_PORT |= (1 << BUTTON); // enable pull up resistor for button input pin
    LED_PORT = 0b10101010;

    while(1)
    {
		if (animationIndexChanged){
			break;
		}
		if (debounce(BUTTON)) {
			if (buttonWasPressed == 0){
    				LED_PORT ^= 0xff;
    				buttonWasPressed = 1;
			}
    		}
    		else {
    			buttonWasPressed = 0;
    		}
    }
}


