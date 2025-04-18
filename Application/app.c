/*
 * app.c
 *
 *  Created on: Mar 22, 2025
 *      Author: Ahmed Mostafa
 */

/*******************************************************************************
 *                            libraries implemented                            *
 *******************************************************************************/

#include "../HAL/LM35/lm35_sensor.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/Buzzer/buzzer.h"
#include "../HAL/Flame/flame.h"
#include "../HAL/LDR/ldr.h"
#include "../HAL/LED/leds.h"
#include "../HAL/Motor/motor.h"
#include "../MCAL/ADC/adc.h"
#include "../MCAL/GPIO/gpio.h"

int main(void)
{
	/*******************************************************************************
	 *                                Initializations                              *
	 *******************************************************************************/
	LCD_init();
	LCD_DisplayStringRowColumn(1, 0, "Temp=   LDR=   %");
	LCD_DisplayStringRowColumn(0,3,"FAN is ");

	ADC_init();

	LEDS_init();

	DcMotor_init();

	Buzzer_init();

	FlameSensor_init();

	uint8 intensity = 0;  /*for light intensity*/

	uint8 temp = 0;  /*for temperature value*/

	boolean flame = FALSE;  /*for checking presence of flame*/

	for(;;)
	{
		flame = FlameSensor_getValue();
		if(flame == TRUE)
		{
			LCD_ClearScreen();
			Buzzer_on();
			LCD_DisplayString("Critical Alert!");
			while(flame == TRUE)
			{
				flame = FlameSensor_getValue();
			}
			Buzzer_off();
			LCD_ClearScreen();
			LCD_DisplayStringRowColumn(1, 0, "Temp=   LDR=   %");
			LCD_DisplayStringRowColumn(0,3,"FAN is ");
		}

		intensity = LDR_getIntensity();
		LCD_MoveCursor(1,12);
		LCD_IntegerToString(intensity);

		if(intensity < 100)
		{
			LCD_DisplayCharacter(' ');
		}

		if(intensity < 16)
		{
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_on(BLUE_LED_ID);
		}
		else if((intensity >= 16) && (intensity <= 50))
		{
			LED_on(RED_LED_ID);
			LED_on(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}
		else if((intensity >= 51) && (intensity <= 70))
		{
			LED_on(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}
		else
		{
			LED_off(RED_LED_ID);
			LED_off(GREEN_LED_ID);
			LED_off(BLUE_LED_ID);
		}

		temp = LM35_getTemperature();
		LCD_MoveCursor(1,5);
		LCD_IntegerToString(temp);

		if(temp < 100)
		{
			LCD_DisplayCharacter(' ');
		}

		if(temp < 25)
		{
			LCD_DisplayStringRowColumn(0,10,"OFF");
			DcMotor_Rotate(STOP,0);
		}
		else
		{
			LCD_DisplayStringRowColumn(0,10,"ON ");
			if((temp >=25) &&(temp < 30))
			{
				DcMotor_Rotate(A_CW,25);
			}
			else if((temp >=30) &&(temp < 35))
			{
				DcMotor_Rotate(A_CW,50);
			}
			else if((temp >=35) &&(temp < 40))
			{
				DcMotor_Rotate(A_CW,75);
			}
			else if(temp >=40)
			{
				DcMotor_Rotate(A_CW,100);
			}
		}
	}
}
