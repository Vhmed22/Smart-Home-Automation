/*
 * adc.h
 *
 *  Created on: Mar 8, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef ADC_H_
#define ADC_H_

#include"../../common_macros.h"
#include"../../std_types.h"


#define ADC_MAX_VALUE       1023
#define ADC_MAX_REF_VOLT    5
#define ADC_REF_VOLT_VALUE  2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_ReadChannel(uint8 ch_num);

#endif /* ADC_H_ */
