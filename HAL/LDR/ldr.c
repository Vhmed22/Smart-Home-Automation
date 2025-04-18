/*
 * ldr.c
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#include "ldr.h"
#include "../../MCAL/ADC/adc.h"

/*
 * Description:
 * Reads the LDR sensor value and returns the light intensity.
 */

uint16 LDR_getIntensity(void)
{

	uint16 ldr_reading = 0;
	uint16 adc_reading = ADC_ReadChannel(LDR_SENSOR_CHANNEL);
	ldr_reading = (uint16)(((uint32)adc_reading * LDR_SENSOR_MAX_LIGHT_INTENSITY)/ ADC_MAX_VALUE );
	if (ldr_reading > LDR_SENSOR_MAX_LIGHT_INTENSITY)
	{
		ldr_reading= LDR_SENSOR_MAX_LIGHT_INTENSITY;
	}
	return ldr_reading;

	/*
	uint16 adc_value =0;
	uint16 light_intensity =0;
	adc_value=ADC_ReadChannel(LDR_SENSOR_CHANNEL);

	float64 v_out=(adc_value * ADC_REF_VOLT_VALUE) / ADC_MAX_VALUE;
	//uint16 light_intensity=(uint16)((v_out/LDR_SENSOR_MAX_VOLT_VALUE)*LDR_SENSOR_MAX_LIGHT_INTENSITY);
	// Ensure that the light intensity is within 0-100%
	light_intensity = (uint16)(v_out * LDR_SENSOR_MAX_LIGHT_INTENSITY / LDR_SENSOR_MAX_VOLT_VALUE);
	if (light_intensity > LDR_SENSOR_MAX_LIGHT_INTENSITY) {
		light_intensity= LDR_SENSOR_MAX_LIGHT_INTENSITY;
	}
	return light_intensity;
*/
}
