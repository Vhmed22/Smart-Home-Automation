/*
 * buzzer.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID      PORTD_ID
#define BUZZER_PIN_ID       PIN3_ID

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*
 * Description:
 * function to initialize the buzzer
 */

void Buzzer_init(void);

/*
 * Description:
 * function to activate the buzzer
 */

void Buzzer_on(void);

/*
 * Description:
 * function to disable the buzzer
 */

void Buzzer_off(void);

#endif /* HAL_BUZZER_BUZZER_H_ */
