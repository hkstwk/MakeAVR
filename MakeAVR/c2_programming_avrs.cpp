#include "pinDefines.h"
#include "c2_programming_avrs.h"

//void blinkingLed(){
//    LED_DDR  |= (1 << LED);
//
//	//Configure 16-bit timer
//    OUTPUT_COMPARE = 15625;
//    TIMER_INTERRUPT_MASK = COMPARE_MATCH_INTERRUPT;
//    TIMER_REGISTER_B |= CTC_MODE | CLOCK_SELECT;
//    sei();
//}
//
//ISR(TIMER1_COMPA_vect)
//{
//	LED_PORT ^= (1 << LED);
//}
