#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

// Fundering, ändra alla coil funktioner till en array som PORTC får värde ifrån.

int stepper_motor[2][8] = {
	{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001} ,
	{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001}
};



int main(void)
{
	DDRC |= 0xFF;
	DDRB = 0x00;
	PORTB = 0x01;
	// Variable to set movement of the stepper motor.
	int forward=1;
	int stepper_movement=0;
	while (1)
	{
		if((PINB & (1<<PB0)) == 0) {
			forward=0;
			} else {
			forward=1;
		}

		if(forward) {
			if(stepper_movement<7){
				stepper_movement++;
			} else {
				stepper_movement=0;
			}
		} else {
			if(stepper_movement>0) {
				stepper_movement--;
			} else {
				stepper_movement=7;
			}
		}

		PORTC = stepper_motor[1][stepper_movement];
		_delay_us(700);


	}
}










/*void (*coil)();
void coil1();
void coil12();
void coil2();
void coil23();
void coil3();
void coil34();
void coil4();
void coil41();

void coil1() {
	PORTC = 0b00000001;
	// if(forward) { coil = coil12; } else { coil = coil41; }
	coil = forward ? coil12 : coil41;
}
void coil12() {
	PORTC = 0b00000011;
	coil = forward ? coil2 : coil1;
}
void coil2() {
	PORTC = 0b00000010;
	coil = forward ? coil23 : coil12;
}
void coil23() {
	PORTC = 0b00000110;
	coil = forward ? coil3 : coil2;
}
void coil3() {
	PORTC = 0b00000100;
	coil = forward ? coil34 : coil23;
}

void coil34() {
	PORTC = 0b00001100;
	coil = forward ? coil4 : coil3;
}
void coil4() {
	PORTC = 0b00001000;
	coil = forward ? coil41 : coil34;
}
void coil41() {
	PORTC = 0b00001001;
	coil = forward ? coil1 : coil4;
}*/
