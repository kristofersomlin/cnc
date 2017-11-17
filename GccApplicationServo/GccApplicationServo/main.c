/*
 * Servo.c
 *
 * Created: 2017-11-07 11:45:12
 * Author : Joel
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#define SERVO_MOTOR_ACAPTED_HZ 50
#define PULSE_WIDTH  2000

int main(void)
{
	DDRB |= 0xFF;
	//PWM FAST MODE
    TCCR1A |= 1 << WGM11 | 1 << COM1A1 | 1 << COM1A0;;
	TCCR1B |= 1 << WGM12 | 1 << WGM13 | 1 << CS10;
	ICR1 = F_CPU / SERVO_MOTOR_ACAPTED_HZ;
	//Inverted trigger on high 
 
	OCR1A = (ICR1 - PULSE_WIDTH);
	    
 

    while (1) 
    {
		
		OCR1A = ICR1 - 2600;
		_delay_ms(2200);
		OCR1A = ICR1 - 1500;//2500
		_delay_ms(2000);
    }
}
