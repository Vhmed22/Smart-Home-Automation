/*
 * pwm.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "pwm.h"
#include <avr/io.h>
#include"../GPIO/gpio.h"

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0;  /*initial timer value equal to zero*/
	uint8 duty = (uint8)(((float32)duty_cycle / 100) * 255);
	OCR0 = (uint8)duty;  /*compare match value for PWM timer*/
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);  /*set PB3 "OC0" as output pin*/
	/*settings of timer control register
	 * fast pwm mode --> WGM00 = 1 , WGM01 = 1 , FOC0 = 0
	 * compare output mode "Non-inverting" --> COM01 = 1 , COM00 = 0
	 * Pre-Scaler = 1024 ---> CS00 = 1 , CS01 = 0 , CS02 = 1*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);
}
