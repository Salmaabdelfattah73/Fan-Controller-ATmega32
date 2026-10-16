#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
#define LCD_BIT_DATA_MODE   8
#if ((LCD_BIT_DATA_MODE) !=4 && (LCD_BIT_DATA_MODE) !=8)
#error "THE MODE SHOULD BE 4 OR 8"
#endif
// LCD HW Ports and Pins Ids Configuration
#define LCD_RS_PORT_ID     PORTD_ID
#define LCD_RS_PIN_ID      PIN0_ID
#define LCD_RW_PORT_ID     PORTD_ID
#define LCD_RW_PIN_ID      PIN1_ID
#define LCD_EN_PORT_ID     PORTD_ID
#define LCD_EN_PIN_ID      PIN2_ID
#define LCD_DATA_PORT_ID   PORTC_ID
// configuration of 4 bit mode
#if (LCD_BIT_DATA_MODE==4)
#define LCD_DB4_PIN_ID   PIN3_ID
#define LCD_DB5_PIN_ID   PIN4_ID
#define LCD_DB6_PIN_ID   PIN5_ID
#define LCD_DB7_PIN_ID   PIN6_ID
#endif
//LCD COMMANDS

#define LCD_CLEAR_DISPLAY                    0x01
#define LCD_RETURN_HOME                      0x02
#define LCD_CURSOR_ON                        0x0E
#define LCD_CURSOR_OFF                       0x0C
#define LCD_TWO_LINES_FOUR_BIT_MODE          0x28
#define LCD_TWO_LINES_EIGHT_BIT_MODE         0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_displayString(const uint8 * str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,uint8* st_row_col);
void LCD_clearScreen(void);
void LCD_intgerToString(int num);
#endif
