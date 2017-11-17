#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

int forward=0;
void (*coil)();
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
}


int main(void)
{
	DDRC |= 0xFF;
	coil=coil1;
	while (1)
	{
		
		coil();
		_delay_us(700);
	}
}