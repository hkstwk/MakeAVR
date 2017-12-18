#include <avr/delay.h>
#include "pinDefines.h"
#include "makeavr_util.h"
#include "c2_programming_avrs.h"

extern volatile uint8_t animationIndexChanged;

void blinkingLed(){
    LED_DDR  |= (1 << LED);

	//Configure 16-bit timer
    OUTPUT_COMPARE = 15625;
    TIMER_INTERRUPT_MASK = COMPARE_MATCH_INTERRUPT;
    TIMER_REGISTER_B |= CTC_MODE | CLOCK_SELECT;
    sei();
}

void blinkingLed2(){
	clearLeds();
    LED_DDR  |= (1 << LED3);

    while (1){
		if (animationIndexChanged){
			break;
		}
		LED_PORT ^= (1 << LED3);
		_delay_ms(50);
    }
}

ISR(TIMER1_COMPA_vect)
{
	LED_PORT ^= (1 << LED);
}
