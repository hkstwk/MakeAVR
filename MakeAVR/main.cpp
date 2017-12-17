#include "pinDefines.h"
#include "makeavr_util.h"
#include "c2_programming_avrs.h"
#include "c3_digital_output.h"
#include "c4_bit_twiddling.h"
#include "c5_serial_io.h"
#include "c6_digital_input.h"
#include "c8_hardware_interrupts.h"


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

volatile uint8_t animationIndex;

int main (void)
{
	// Init stuff is done in pinDefines.h
	LED_DDR = 0xff;

	/* Set toggle button pin to input by clearing the bit. Safety precaution */
	BUTTON_DDR &= ~(1 << BUTTON_TGL);
	/* enable pull up resistor for toggle button pin */
	BUTTON_PORT |= (1 << BUTTON_TGL);
	/* Intitalize interrupt for toggle button on INT1 */
	initInterrupt1();

	animationIndex = 0;

	while(1)
    {
		switch (animationIndex){
		   case 0:
		      PovAnimate();
		      break;
		   case 1  :
			   CountBinary();
		      break;
		   default :
			   blinkingLed();
			   break;
		}

//   		PovAnimate();
//    		CountBinary();
//    		cyclonEyesOr();
//    		_delay_ms(DELAY);
//    		cyclonEyes();
//    		_delay_ms(DELAY);
//    		cyclonEyesInverted();
//    		_delay_ms(DELAY);
//    		toggleButton();
//    		blinkingLed();
//		serialLoopback();
//		testSerial();
		ledInterruptToggle();
    }

    return 0;
}
