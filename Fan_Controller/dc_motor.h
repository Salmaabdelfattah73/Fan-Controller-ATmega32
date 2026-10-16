#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"
#define DC_PORT_ID   PORTB_ID
#define DC_FIRST_PIN_ID     PIN0_ID
#define DC_SECOND_PIN_ID    PIN1_ID


typedef enum{
	stop,clock_wise,anti_clock_wise
}DcMotor_State;

void DcMotor_init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* DC_MOTOR_H_ */
