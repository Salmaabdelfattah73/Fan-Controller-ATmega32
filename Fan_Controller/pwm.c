#include "pwm.h"
#include "gpio.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;
	OCR0=duty_cycle;
	GPIO_setupPinDirection(PWM_PORT_ID ,PWM_PIN_ID,PIN_OUTPUT);
	TCCR0=(1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
