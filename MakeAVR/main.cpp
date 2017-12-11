#include "pinDefines.h"
#include "buttonStuff.h"

void POVDisplay(uint8_t oneByte) {
	LED_PORT = oneByte;
	_delay_ms(10);
}

void CountBinary(){
	for (uint8_t i=0;i<=255;i++){
		POVDisplay(i);
		if (i == 255) {
			_delay_ms(2000);
		} else {
			_delay_us(1);
		}
	}
}

void PovAnimate(){
	POVDisplay(0b00001110);
	POVDisplay(0b00011000);
	POVDisplay(0b10111101);
	POVDisplay(0b01110110);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b00111100);
	POVDisplay(0b01110110);
	POVDisplay(0b10111101);
	POVDisplay(0b00011000);
	POVDisplay(0b00001110);

	LED_PORT = 0;
	_delay_ms(DELAY);
}

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

int main (void)
{
    LED_DDR   = 0xff;
    SHREG_DDR |= (1 << DATA) | (1 << SHIFT) | (1 << LATCH);



    while(1)
    {
//    		PovAnimate();
//    		CountBinary();
//    		cyclonEyesOr();
//    		_delay_ms(DELAY);
//    		cyclonEyes();
//    		_delay_ms(DELAY);
//    		cyclonEyesInverted();
//    		_delay_ms(DELAY);
    		toggleButton();
    }
    return 0;
}
