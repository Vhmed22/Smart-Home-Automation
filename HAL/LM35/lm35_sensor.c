/*
 * lm35_sensor.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "lm35_sensor.h"
#include "../../MCAL/ADC/adc.h"

uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
	uint16 adc_value = 0;

	/*Read ADC Channel where the temperature sensor is connected*/
	adc_value = ADC_ReadChannel(SENSOR_CHANNEL_ID);

	/*calculating temperature value*/
	temp_value = (uint8)(((uint32)adc_value * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE)/(ADC_MAX_VALUE * SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}
