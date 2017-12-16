#include "pinDefines.h"
#include "c2_programming_avrs.h"
#include "c3_digital_output.h"
#include "c4_bit_twiddling.h"
#include "c5_serial_io.h"
#include "c6_digital_input.h"


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

int main (void)
{
	// Init stuff is done in pinDefines.h
	LED_DDR = 0xff;

	while(1)
    {
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
		serialLoopback();
//		testSerial();
    }

    return 0;
}
