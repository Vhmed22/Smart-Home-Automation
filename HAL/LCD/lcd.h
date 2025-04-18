/*
 * LCD.h
 *
 *  Created on: Feb 28, 2025
 *      Author: Ahmed Mostafa
 */

#ifndef LCD_H_
#define LCD_H_
#include "../../std_types.h"

/*LCD data bits configuration*/
#define LCD_DATA_BITS_MODE     8
#if(LCD_DATA_BITS_MODE !=4 && LCD_DATA_BITS_MODE !=8)

#error "Number of Data bits must be equal to 4 or 8"

#endif

/*LCD HW Ports and pins ID*/
#define LCD_RS_PORT_ID         PORTD_ID
#define LCD_RS_PIN_ID          PIN0_ID

#define LCD_E_PORT_ID          PORTD_ID
#define LCD_E_PIN_ID           PIN1_ID

#define LCD_DATA_PORT_ID       PORTC_ID

#if(LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID         PIN3_ID
#define LCD_DB5_PIN_ID         PIN4_ID
#define LCD_DB6_PIN_ID         PIN5_ID
#define LCD_DB7_PIN_ID         PIN6_ID

#endif

/*LCD Commands*/
#define LCD_CLEAR_SCREEN                     0x01
#define LCD_RETURN_HOME                      0x02
#define LCD_SHIFT_CURSOR_LEFT                0x04
#define LCD_SHIFT_CURSOR_RIGHT               0x06
#define LCD_SHIFT_DISPLAY_RIGHT              0x05
#define LCD_SHIFT_DISPLAY_LEFT               0x07
#define LCD_CURSOR_ON                        0x0E
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_LOCATION                  0x80
#define LCD_CURSOR_BLINKING                  0x0D
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */

void LCD_init();

/*
 * Description :
 * Send the required command to the screen
 */

void LCD_SendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */

void LCD_DisplayCharacter(uint8 Character);

/*
 * Description :
 * Display the required string on the screen
 */

void LCD_DisplayString(const char *string);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */

void LCD_MoveCursor(uint8 row,uint8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */

void LCD_DisplayStringRowColumn(uint8 row, uint8 col,const char *string );

/*
 * Description :
 * Display the required decimal value on the screen
 */

void LCD_IntegerToString(int data);

/*
 * Description :
 * Send the clear screen command
 */

void LCD_ClearScreen(void);

#endif /* LCD_H_ */
