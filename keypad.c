#include "keypad.h"
 const unsigned char arr[4][4]={{0,1,2,3},
 	                          {4,5,6,7},
 							  {8,9,10,11},
 							  {12,13,14,15},
  							  };

void keypad_Init()
{
	
	CLR_BIT(DDRD,PIN7);
	CLR_BIT(DDRD,PIN6);
	CLR_BIT(DDRD,PIN5);
	CLR_BIT(DDRD,PIN3);
	
	
	SET_BIT(DDRC,PIN5);
	SET_BIT(DDRC,PIN4);
	SET_BIT(DDRC,PIN3);
	SET_BIT(DDRC,PIN2);
	

	SET_BIT(PORTD,PIN7);	
	SET_BIT(PORTD,PIN6);
	SET_BIT(PORTD,PIN5);
	SET_BIT(PORTD,PIN3);
}		

unsigned char keypad_get_value(void)
{

	
	unsigned char col,row, ans= INVALID_KEYPAD_PRESS;
	for (row=5;row>=2;row--)
	{
		PORTC |=0b00111100;
		CLR_BIT(PORTC,row);
		for (col=7;col>=3;col--)
		{
			if (col==4)
				col--;
			if (GET_BIT(PIND,col)==0)
			{
				_delay_ms(150);
				//_delay_ms(120);
				if (GET_BIT(PIND,col)==0)
				{
					if (col==3)
					{
						ans=arr[5-row][7-col-1];
						break;
					}
					else
					{
						
						ans=arr[5-row][7-col];
						break;
					}
				}
			}
			
		}
		
	}
	return ans;	
} 	

			  