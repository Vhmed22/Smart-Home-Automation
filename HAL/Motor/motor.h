/*
 * motor.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

#include"../../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_PORT_ID               PORTB_ID
#define MOTOR_IN1_PIN_ID            PIN0_ID
#define MOTOR_IN2_PIN_ID            PIN1_ID

typedef enum{
	STOP , CW , A_CW
}DcMotor_State;
/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*
 * Description:
 * Initializes the DC motor by setting the direction for the motor pins and stopping the
 * motor at the beginning.
 */

void DcMotor_init(void);

/*
 * Description:
 * Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
 * on the input duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state , uint8 speed);

#endif /* HAL_MOTOR_MOTOR_H_ */
