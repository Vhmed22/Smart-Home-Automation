/*
 * leds.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef HAL_LED_LEDS_H_
#define HAL_LED_LEDS_H_

#include "../../std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define RED_LED_PORT_ID         PORTB_ID
#define RED_LED_PIN_ID          PIN5_ID

#define GREEN_LED_PORT_ID       PORTB_ID
#define GREEN_LED_PIN_ID        PIN6_ID

#define BLUE_LED_PORT_ID        PORTB_ID
#define BLUE_LED_PIN_ID         PIN7_ID

#define POSITIVE_LOGIC

#ifdef POSITIVE_LOGIC
#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW

#endif

#ifdef NEGATIVE_LOGIC
#define LED_ON LOGIC_LOW
#define LED_OFF LOGIC_HIGH

#endif

typedef enum{
	RED_LED_ID , GREEN_LED_ID , BLUE_LED_ID
}LED_ID;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * function to initizalize leds
 */

void LEDS_init(void);

/*
 * Description:
 * function to Turn on specified leds
 */

void LED_on(LED_ID id);

/*
 * Description:
 * function to Turn off specified leds
 */

void LED_off(LED_ID id);

#endif /* HAL_LED_LEDS_H_ */
