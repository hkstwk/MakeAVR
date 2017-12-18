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
volatile uint8_t animationIndexChanged;

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
	animationIndexChanged = 0;

	while(1)
    {
		/* check if animationIndexChanged is set by INT1 (see makeavr_utils.cpp).
		 * If so, reset to false (= 0) */
		if (animationIndexChanged == 1){
			animationIndexChanged = 0;
		}
		switch (animationIndex){
		   case 0:
		      PovAnimate();
		      break;
		   case 1:
			   CountBinary();
		      break;
		   case 2:
			  cyclonEyesOr();
		      break;
		   case 3:
			  cyclonEyes();
		      break;
		   case 4:
			  cyclonEyesInverted();
		      break;
		   case 5:
			  blinkingLed2();
		      break;
		   default :
			   blinkingLed2();
			   break;
		}
//    		toggleButton();
//    		blinkingLed();
//			serialLoopback();
//			testSerial();
//			ledInterruptToggle();
    }

    return 0;
}
