#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

struct stepper_motor {
	uint8_t stepper_values[8];
	int forward;
	int stepper_movement;
	volatile uint8_t *port;
} stepper_motors[2] = {
	{{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001},1,0,&PORTC},
	{{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001},1,0,&PORTB}
};

// Ändra denna funktion till en int som returnerar 1 om den funkar och 0 om det blir fel?!?!?!?!?
void stepper_move(int stepper) {
	if(stepper_motors[stepper].forward) {
		if(stepper_motors[stepper].stepper_movement<7){
			stepper_motors[stepper].stepper_movement++;
		} else {
			stepper_motors[stepper].stepper_movement=0;
		}
	} else {
		if(stepper_motors[stepper].stepper_movement>0) {
			stepper_motors[stepper].stepper_movement--;
		} else {
			stepper_motors[stepper].stepper_movement=7;
		}
	}
		// Setting PORTB / PORTC to the value depending on what stepper is used.
		*stepper_motors[stepper].port = stepper_motors[stepper].stepper_values[stepper_motors[stepper].stepper_movement];
		//PORTC = stepper_motors[stepper].stepper_values[stepper_motors[stepper].stepper_movement];
}
/*
void button_check() {
	if((PINB & (1<<PB0)) == 0) {
		stepper_motors[0].forward=0;
		} else {
		stepper_motors[0].forward=1;
	}
}
*/
int main(void) {
	DDRC |= 0xFF;
	DDRB |= 0xFF;
	//PORTB = 0x01;

	while (1)
	{
		//button_check();
		stepper_move(0);
// 		_delay_us(700);
 		stepper_move(1);
		_delay_us(90);
	
	}
}
