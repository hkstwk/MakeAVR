#include "pinDefines.h"
//#include "c2_programming_avrs.h"
#include "c3_digital_output.h"
//#include "c4_bit_twiddling.h"
//#include "c6_digital_input.h"

void clearLeds(){
	LED_PORT = 0x00;
	_delay_ms(DELAY);
}

void cyclonEyes(){
	uint8_t i = 0;
	while (i < 7){
		LED_PORT = (1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT = (1 << i);
		_delay_ms(DELAY);
		i--;
	}
	LED_PORT = (0 << 0);
}

void cyclonEyesOr(){
	uint8_t i = 0;
	while (i <= 7){
		LED_PORT |= (1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT &= ~(1 << i);
		_delay_ms(DELAY);
		i--;
	}
	LED_PORT |= (0 << 0);
}

void cyclonEyesInverted(){
	uint8_t i = 0;
	while (i < 7){
		LED_PORT = ~(1 << i);
		_delay_ms(DELAY);
		i++;
	}
	while (i < 255){
		LED_PORT = ~(1 << i);
		_delay_ms(DELAY);
		i--;
	}
	clearLeds();
}

void shiftClock(){
	SHREG_PORT |= (1 << SHIFT); //HIGH
	SHREG_PORT &= ~(1 << SHIFT); //LOW
}

void shiftLatch(){
	SHREG_PORT |= (1 << LATCH); //HIGH
	SHREG_PORT &= ~(1 << LATCH); //LOW
}

void shiftData(){
	SHREG_PORT |= (1 << DATA); //HIGH
	SHREG_PORT &= ~(1 << DATA); //LOW
}

uint8_t debounce(void){
	if (!(PIND & (1 << BUTTON))){       /* button is pressed */
		_delay_us(DEBOUNCE_TIME);
		if (!(PIND & (1 << BUTTON))){   /* button is still pressed */
			return (1);
		}
	}
	return (0);
}

void toggleButton(){
	uint8_t buttonWasPressed = 0;
    BUTTON_DDR &= ~(1 << BUTTON); // Set button pin to input by clearing the bit. Safety precaution
    BUTTON_PORT |= (1 << BUTTON); // enable pull up resistor for button input pin
    LED_PORT = 0b00111100;

    while(1)
    {
		if (debounce()) {
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


int main (void)
{
	// Init stuff is done in pinDefines.h
	LED_DDR = 0xff;

	while(1)
    {
   		PovAnimate();
    		CountBinary();
//    		cyclonEyesOr();
//    		_delay_ms(DELAY);
//    		cyclonEyes();
//    		_delay_ms(DELAY);
//    		cyclonEyesInverted();
//    		_delay_ms(DELAY);
//    		toggleButton();
//    		blinkingLed();
    }

    return 0;
}
