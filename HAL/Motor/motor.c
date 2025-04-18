/*
 * motor.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "motor.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/pwm.h"

/*
 * Description:
 * Initializes the DC motor by setting the direction for the motor pins and stopping the
 * motor at the beginning.
 */

void DcMotor_init(void)
{
	/*set motor pins as output pins*/
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_IN1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_IN2_PIN_ID,PIN_OUTPUT);

	/*initialize motor state "OFF"*/
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN2_PIN_ID,LOGIC_LOW);
}

/*
 * Description:
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
 * on the input duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state , uint8 speed)
{

	/*Update state of the motor*/
	if(state == STOP)
	{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	else if(state == A_CW){
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_HIGH);
	}
	else if(state == CW){
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);
	}
	else{
		/*Do Nothing*/
	}

	/*Update Speed*/
	PWM_Timer0_Start(speed);

	/*
	switch(state)
	{
	case STOP:
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN2_PIN_ID,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN2_PIN_ID,LOGIC_HIGH);
		break;
	case A_CW:
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN1_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID,MOTOR_IN2_PIN_ID,LOGIC_LOW);
		break;
	}
	PWM_Timer0_Start(speed);*/
}

