#include  "gpio.h"
#include  "dc_motor.h"
#include  "pwm.h"

void DcMotor_init(void){
	GPIO_setupPinDirection(DC_PORT_ID ,DC_FIRST_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_PORT_ID ,DC_SECOND_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(DC_PORT_ID,DC_FIRST_PIN_ID,LOGIC_LOW );
	GPIO_writePin(DC_PORT_ID,DC_SECOND_PIN_ID,LOGIC_LOW );
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	if(state == clock_wise)
	{//rotate with clock wise direction
		GPIO_writePin(DC_PORT_ID,DC_SECOND_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_PORT_ID,DC_FIRST_PIN_ID,LOGIC_HIGH);
	}
	else if(state == anti_clock_wise)
	{//rotate with anti clock wise direction
		GPIO_writePin(DC_PORT_ID,DC_FIRST_PIN_ID ,LOGIC_HIGH);
		GPIO_writePin(DC_PORT_ID,DC_SECOND_PIN_ID,LOGIC_LOW);
	}
	else
	{ //stop the DC_Motor
		GPIO_writePin(DC_PORT_ID,DC_SECOND_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_PORT_ID,DC_FIRST_PIN_ID,LOGIC_LOW);
	}
	if(speed==25){
		speed=64;               // 25% of 255
	}
	else if(speed==50){
		speed=128;              //50% of 255*
	}
	else if(speed==75){
		speed=192;             // 75% of 255
	}
	else if (speed==100){
		speed=255;             // 100% of 255
	}
	PWM_Timer0_Start(speed);
}
