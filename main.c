/*
 * GccApplication6.c
 *
 * Created: 5/13/2023 10:25:35 PM
 * Author : hp
 */ 

#define F_CPU 16000000
#include "seven_seg.h"
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "LCD.h"
#include "clc.h"
#include "keypad.h"
#include "timer0.h"

void tohalfdelay();
void halfdelay(int time);
int num2[2],l=0;
uint8 g_tick=0;
//uint8 sec_counter=0;
void todelay()
{
	int a=0,b=0,c=0,d=0,e=0;
	g_tick++;//61
	if (g_tick==NUMBER_OF_OVERFLOW)
	{
		e=num2[l];
		a=(e%10); //1234 (4)  ahad   1
		b=((e/10)%10); //1234 (3) ten  2
		c=((e/100)%10); //1234 (2)  met   3
		d=(e/1000)%10; //1234(1)  alf  4
		if (e!=0)
		{
			uint16 st=0;
			while(st<1000)
			{
				
			//
			SET_BIT(PORTA,PIN2);
			SET_BIT(PORTA,PIN3);
			SET_BIT(PORTB,PIN5);
			CLR_BIT(PORTB,PIN6);
			seven_seg_display(d);
			//
		    halfdelay(10);//10ms
			//halfdelay(178)//5ms	
			SET_BIT(PORTA,PIN2);
			SET_BIT(PORTA,PIN3);
			SET_BIT(PORTB,PIN6);
			CLR_BIT(PORTB,PIN5);
			seven_seg_display(c);
			//
	     	halfdelay(10);
			SET_BIT(PORTA,PIN3);
			SET_BIT(PORTB,PIN5);
			SET_BIT(PORTB,PIN6);
			CLR_BIT(PORTA,PIN2);
			seven_seg_display(b);
			//
			halfdelay(10);
			SET_BIT(PORTA,PIN2);
			SET_BIT(PORTB,PIN5);//
			SET_BIT(PORTB,PIN6);
			CLR_BIT(PORTA,PIN3);
			seven_seg_display(a);
			//
			halfdelay(10);
		st+=5;
		}
		
		}
		SET_BIT(PORTA,PIN3);
		l++;	
			g_tick=0;
	}
}

void halfdelay(int time)
{
	uint8 y,z;
	for(y=0;y<time;y++)
	for(z=0;z<254;z++);
}

int inttoarray(int a[],int s){
		int i;
		int temp1=0;
		for (i=0;i<s;i++)
		{
			
			temp1=temp1*10+a[i];
		}
	    return temp1;
	}
	
void sorting(int arr[],int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1]) //compare adjacent elements
			{
				temp = arr[j]; //swap them if they are out of order
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}

int main(void)
{
	TIMER0_init();
	int value;
	LCD_Init();
	keypad_Init();
	lcd_clear();
	int s=0;
	seven_segment_init();
    /* Replace with your application code */
	int i=0,k=0;
	int numsort[4],c=0,num3[4];
	//timer0_setcalback(todelay);	
    while (1) 
    {
		value=keypad_get_value();
		if (value!=INVALID_KEYPAD_PRESS)
		{
			halfdelay(90);//120
			int num1[4];
				if (value!=15)//+
				{ 
				 num1[i]=getnum(value);
				LCD_Char(num1[i]+'0');
				i++;
				}
				else if(value==15)//+
				{
				   num2[k]=inttoarray(num1,i);
					LCD_Char(',');
					 i=0;
					s++;
					k++;
				}
				if(value==14)//=
				{
					lcd_gotoxy(1,0);
					LCD_String("sort number: =");
				sorting(num2,s);

                
				for (int i=0;i<s;i++)
				{
					
					halfdelay(5);//150
					
					CLCD_voidWriteNumber(num2[i]);
					
					//LCD_Char(num2[i]+'0');
					
					if(i+1<s)
					LCD_Char(',');	
				}	
                } 
				 if (value==12)//c
					{
						lcd_clear();
					//	SET_BIT(LCD_Command, RW);
					//	todelay();
						timer0_setcalback(todelay);	
					}
	               if (value==11)//-
	                 {
		             lcd_clear();
	               }
              }

	}
}
