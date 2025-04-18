/*
 * lm35_sensor.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_LM35_SENSOR_H_
#define HAL_LM35_SENSOR_H_

#include "../../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* HAL_LM35_SENSOR_H_ */
