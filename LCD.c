#include "LCD.h"

#define SET_CURSOR_LOCATION (0x80)
void LCD_Init (void)/* LCD Initialize function */
{
	//LCD_Command_Dir|=(1<<RS) | (1<<EN); // Make command port as o/p
	//LCD_Data_Direction|= 0b00010111; // Make data port as o/p
	SET_BIT(LCD_Command_Dir,PIN3);
	SET_BIT(LCD_Command_Dir,PIN2);
	//SET_BIT(LCD_Command_Dir,PIN1); //
	
	SET_BIT(LCD_Data_Direction,PIN0);
	SET_BIT(LCD_Data_Direction,PIN1);
	SET_BIT(LCD_Data_Direction,PIN2);
	SET_BIT(LCD_Data_Direction,PIN4);
	_delay_ms(15);// LCD Power ON delay always >15ms
	LCD_Command (0x02);//Initialize the LCD in 8bit mode
	LCD_Command (0x28);//Initialize the LCD in 8bit mode
	LCD_Command (0x0C);/* Display ON Cursor OFF */
	LCD_Command (0x06);/* Auto Increment cursor */
	LCD_Command (0x01);/* clear display */
	LCD_Command (0x80);/* cursor at home position */
}

void LCD_Command(unsigned char cmnd)
{
	PORTB &=0b11101000;
	PORTB|=(((((cmnd& 0xF0)>>4)&0b00001000)<<1) | (((cmnd &0xF0)>>4)&0b00000111));
	CLR_BIT(LCD_Command_Port, RS);
   // CLR_BIT(LCD_Command_Port, RW);//
	SET_BIT(LCD_Command_Port,EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port, EN);
	_delay_ms(2);
	PORTB &=0b11101000;
	PORTB|=((((cmnd& 0x0F)&0b00001000)<<1) | ((cmnd &0x0F)&0b00000111));
	SET_BIT(LCD_Command_Port,EN);
	_delay_us(1);
	CLR_BIT(LCD_Command_Port, EN);
	_delay_ms(2);

}


 void LCD_Char (unsigned char char_data)
 {
 	PORTB &=0b11101000;
 	PORTB|=(((((char_data& 0xF0)>>4)&0b00001000)<<1) | (((char_data &0xF0)>>4)&0b00000111));
 	SET_BIT(LCD_Command_Port, RS);
	//CLR_BIT(LCD_Command_Port, RW);//
 	SET_BIT(LCD_Command_Port,EN);
 	_delay_us(1);
 	CLR_BIT(LCD_Command_Port, EN);
	_delay_ms(2);
 	PORTB &=0b11101000;
	  	PORTB|=((((char_data& 0x0F)&0b00001000)<<1) | ((char_data &0x0F)&0b00000111));
 	SET_BIT(LCD_Command_Port,EN);
 	_delay_us(1);
 	CLR_BIT(LCD_Command_Port, EN);
 	_delay_ms(2);
 }

void LCD_String (char *str )
{
	int i;
	for(i=0;str[i]!=0;i++) //send each char of string till NULL

	{
		
		LCD_Char (str[i]);/* call LCD data write */
	}
}

void lcd_clear()
{
	LCD_Command(0x01);
//	SET_BIT(LCD_Command_Port,RW);//
	
	
}
void lcd_gotoxy(unsigned char row,unsigned char col)
{
	unsigned char address=0;
	
	switch(row)
	{
		case 0:
		       address=col;
		       break;
		case 1:
		      address=col+0x40;
		      break;
		case 2:
			address=col+0x14;
			break;	  
		case 3:
			address=col+0x54;
			break;
	}
	LCD_Command(address|SET_CURSOR_LOCATION);
}
//////////////////////////////////////////////////////////////////////////
 /* void lcdchar(unsigned char data){
	 
	  
	 // PORTB &=0b11101000;
	  PORTB=(PORTB &0x0F) | (data &0xF0);
	  SET_BIT(LCD_Command_Port, RS);
	  SET_BIT(LCD_Command_Port,EN);
	  _delay_us(1);
	  CLR_BIT(LCD_Command_Port, EN);
	  _delay_ms(2);
	 
	    PORTB=(PORTB &0x0F) | (data <<4);
	  SET_BIT(LCD_Command_Port,EN);
	  _delay_us(1);
	  CLR_BIT(LCD_Command_Port, EN);
	  _delay_ms(2);
  }*/

	void CLCD_voidWriteNumber(int copy_u32Number)
	{
		int Local_u8Digit;
		int Local_u8Counter=0;
		int Local_u8Counter2;
		static int Local_ArrayOfChar[10]={'0','1','2','3','4','5','6','7','8','9'};
		static int Local_ArrayOfDigits[10];

		if(copy_u32Number==0)
		{
			LCD_Char(Local_ArrayOfChar[0]);
		}
		else
		{

			while(copy_u32Number>0)
			{
				Local_u8Digit=copy_u32Number%10;
				copy_u32Number=copy_u32Number/10;
				Local_ArrayOfDigits[Local_u8Counter]=Local_ArrayOfChar[Local_u8Digit];
				Local_u8Counter++;
			}

			for(Local_u8Counter2=Local_u8Counter-1;Local_u8Counter2>=0;Local_u8Counter2--)
			{
				LCD_Char(Local_ArrayOfDigits[Local_u8Counter2]);
			}
		}
	}


