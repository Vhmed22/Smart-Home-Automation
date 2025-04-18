/*
 * leds.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "leds.h"
#include "../../MCAL/GPIO/gpio.h"

/*
 * Description:
 * function to initizalize leds
 */

void LEDS_init(void)
{
	/*setting leds pins as output pins*/
	GPIO_setupPinDirection(RED_LED_PORT_ID,RED_LED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,PIN_OUTPUT);

	/*initialize leds to be turned off*/
	GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LED_OFF);
	GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LED_OFF);
	GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LED_OFF);
}

/*
 * Description:
 * function to Turn on specified leds
 */

void LED_on(LED_ID id)
{
	switch(id)
	{
	case RED_LED_ID:
		GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LED_ON);
		break;
	case GREEN_LED_ID:
		GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LED_ON);
		break;
	case BLUE_LED_ID:
		GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LED_ON);
		break;
	}
}

/*
 * Description:
 * function to Turn off specified leds
 */

void LED_off(LED_ID id)
{
	switch(id)
	{
	case RED_LED_ID:
		GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LED_OFF);
		break;
	case GREEN_LED_ID:
		GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LED_OFF);
		break;
	case BLUE_LED_ID:
		GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LED_OFF);
		break;
	}
}
