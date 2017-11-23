#define F_CPU 32000000
#include <avr/io.h>
#include <util/delay.h>

struct stepper_motor
{
	uint8_t stepper_values[8];
	int forward;
	int stepper_movement;
	volatile uint8_t *port;
} stepper_motors[2] = {
	{{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001},1,0,&PORTC},
	{{0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001},1,0,&PORTB},
	//{{0b00000011,0b00000110,0b00001100,0b00001001},1,0,&PORTC},
	//{{0b00000011,0b00000110,0b00001100,0b00001001},1,0,&PORTC}
};

// Ändra denna funktion till en int som returnerar 1 om den funkar och 0 om det blir fel?!?!?!?!?
void stepper_move(int stepper)
{
	// Checking if the motor should move forward
	if(stepper_motors[stepper].forward)
	{
		if(stepper_motors[stepper].stepper_movement<7)
		{
			stepper_motors[stepper].stepper_movement++;
		}
		else
		{
			stepper_motors[stepper].stepper_movement=0;
		}
	}
	else
	{
		if(stepper_motors[stepper].stepper_movement>0)
		{
			stepper_motors[stepper].stepper_movement--;
		}

		else
		{
			stepper_motors[stepper].stepper_movement=7;
		}
	}
		// Setting PORTB / PORTC to the value depending on what stepper is used.
		*stepper_motors[stepper].port = stepper_motors[stepper].stepper_values[stepper_motors[stepper].stepper_movement];
}

int main(void)
{

	int max_pwm=240;

	DDRC |= 0xFF;
	DDRB |= 0xFF;
	int pwm_timer=0;
	int maxmovement=0;
	double inc_procent=0.2;
	while (1)
	{
		
 		//stepper_move(1);
		//_delay_us(90);



// STEPPER SKA HA PWM!



		stepper_move(0);
		stepper_move(1);
		for(int i=0;i<pwm_timer;i++) {
			_delay_us(1);
		}

		for(int i=0;i<max_pwm-pwm_timer;i++) {
			_delay_us(1);
		}
		
		
		if (maxmovement<100) {
			inc_procent+=0.01;
			//timershitbalaha++;
			pwm_timer=(int)(inc_procent*(max_pwm*0.96));
		}

		if(maxmovement>300) {
			inc_procent-=0.01;
			//timershitbalaha++;
			pwm_timer=(int)(inc_procent*(max_pwm*0.96));
		}
		if(maxmovement>400) {
			PORTC = 0b00000000;
			PORTB = 0b00000000;
			_delay_ms(600);
			maxmovement=0;
			inc_procent=0.2;
		}
maxmovement++;
		
		//	stepper_motors[0].forward=1;
		

	}
}
