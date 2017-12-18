#include "pinDefines.h"
#include "makeavr_util.h"
#include "c2_programming_avrs.h"
#include "c3_digital_output.h"
#include "c4_bit_twiddling.h"
#include "c5_serial_io.h"
#include "c6_digital_input.h"
#include "c8_hardware_interrupts.h"

/* global variables used to control toggling of animations
 *
 */
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
		      PovAnimateHC595();
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
		   case 6:
			  /* sends letter 'Q' at regular intervals */
			  testSerial();
		      break;
		   case 7:
			  /* type text, set local echo on. after button press,
			   * type one random character in serial monitor
			   * to break the loop */
			  serialLoopback();
		      break;
		   case 8:
			   /* using polling mechanism,
			    * waiting forever for button press*/
			   toggleButton();
		      break;
		   case 9:
			   /* using interrupt INT0,
			    * can do other stuff, stops doing that when
			    * button is pressed */
			   ledInterruptToggle();
		      break;
		   case 10:
		      PovAnimate();
		      break;
		   default :
			   blinkingLed2();
			   break;
		}
    }
    return 0;
}
