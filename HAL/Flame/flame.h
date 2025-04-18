/*
 * flame.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_FLAME_FLAME_H_
#define HAL_FLAME_FLAME_H_

#include "../../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAME_PORT_ID        PORTD_ID
#define FLAME_PIN_ID         PIN2_ID

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*
 * Description:
 * initializes the flame sensor pin direction.
 */

void FlameSensor_init(void);

/*
 * Description:
 * Reads the value from the flame sensor and returns it.
 */

uint8 FlameSensor_getValue(void);

#endif /* HAL_FLAME_FLAME_H_ */
