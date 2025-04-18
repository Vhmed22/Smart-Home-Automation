/*
 * flame.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "flame.h"
#include "../../MCAL/GPIO/gpio.h"


/*
 * Description:
 * initializes the flame sensor pin direction.
 */

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT_ID,FLAME_PIN_ID,PIN_INPUT);
}

/*
 * Description:
 * Reads the value from the flame sensor and returns it.
 */

uint8 FlameSensor_getValue(void)
{
	return GPIO_readPin(FLAME_PORT_ID,FLAME_PIN_ID);
}

