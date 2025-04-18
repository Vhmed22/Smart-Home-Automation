/*
 * ldr.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_LDR_LDR_H_
#define HAL_LDR_LDR_H_

#include "../../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LDR_SENSOR_CHANNEL                    0
#define LDR_SENSOR_MAX_VOLT_VALUE             (2.56f)
#define LDR_SENSOR_MAX_LIGHT_INTENSITY        (100u)

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*
 * Description:
 * Reads the LDR sensor value and returns the light intensity.
 */

uint16 LDR_getIntensity(void);

#endif /* HAL_LDR_LDR_H_ */
