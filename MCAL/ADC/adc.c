/*
 * adc.c
 *
 *  Created on: Mar 8, 2025
 *      Author: Ahmed Mostafa
 */

#include"../GPIO/gpio.h"
#include "adc.h"
#include <avr/io.h>

void ADC_init(void)
{
	/*voltage selection is the maximum voltage reference = 2.56*/
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

	/*setting ADC control status register with the following settings
	 *ADEN = 1 ---> ADC Enable
	 *ADPS0 = 1 , ADPS1 = 1 , ADPS2 = 1 ---> Pre-scaler = 128
	 *ADATE = 0 ---> Disable Auto trigger enable */

	ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}
uint16 ADC_ReadChannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num &= 0x07);  /*setting and choosing the required channel for ADC from MUX4:0*/
	/*Start conversion
	 * ADSC = 1*/
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));  /*wait until the conversion is completed*/
	/*ADC interrupt Flag
	 * ADIF = 1 ---> to clear flag*/
	SET_BIT(ADCSRA,ADIF);
	return ADC;  /*return the value from ADC data register*/
}
