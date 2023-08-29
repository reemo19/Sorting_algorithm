
#ifndef LCD_
#define LCD_

#define F_CPU 16000000

#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#define LCD_Data_Port PORTB // Define LCD data port
#define LCD_Data_Direction DDRB// Define LCD data port direction
#define LCD_Command_Port PORTA// Define LCD data port
#define LCD_Command_Dir DDRA// Define LCD command port direction
#define RS PIN3// Define Register Select (data/command)
//#define RW PIN1  //RW
#define EN PIN2// Define Enable signal pin
void lcdchar(unsigned char data);
	
void LCD_Command(unsigned char cmnd);
void LCD_Init (void);//LCD Initialize function
void LCD_Char (unsigned char char_data);
void LCD_String (char *str);
void lcd_clear();
void lcd_gotoxy(unsigned char row,unsigned char col);
void CLCD_voidWriteNumber(int copy_u32Number);



#endif