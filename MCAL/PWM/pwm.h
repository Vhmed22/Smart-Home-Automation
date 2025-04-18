/*
 * pwm.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../std_types.h"


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with Timer0
 * Timer0 will be used with pre-scaler F_CPU/1024
 * F_PWM=(F_CPU)/(256*N) = (16*10^6)/(256*1024) = 60Hz
 * Generate a PWM signal with frequency 60Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* MCAL_PWM_PWM_H_ */
