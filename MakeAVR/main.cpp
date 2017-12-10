#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT		PORTB
#define LED_DDR		DDRB
#define SHREG_PORT	PORTD
#define	SHREG_DDR	DDRD
#define DATA			PD5
#define SHIFT		PD6
#define LATCH		PD7
#define BUTTON_PORT	PORTD
#define BUTTON_DDR	DDRD
#define BUTTON		PD2
#define DELAY		5 		// delay in milliseconds

#define DEBOUNCE_TIME 1000 // microseconds

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
