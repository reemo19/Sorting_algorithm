/*
 * CFile1.c
 *
 * Created: 4/15/2023 9:15:51 AM
 *  Author: nedaa.ahmed
 */ 

#include "seven_seg.h"
#include "BIT_MATH.h"
#include "std_types.h"
#include "ATmega32_Rrgiosters.h"

void seven_segment_init(void)
{
	SET_BIT(DDRA, PIN3); /*Set PA3 as output to enable the first seven segment*/
	SET_BIT(DDRB, PIN5);
	SET_BIT(DDRB, PIN6);
	SET_BIT(DDRA, PIN2);
//    SET_BIT(DDRA,PIN2);//off 3
  
	DDRB |= 0b00010111; /*Set PB0, PB1, PB2, and PB4 as output*/
}
void seven_seg_display(uint8 num)
{
	PORTB &= 0b11101000; /*Clear the 4 bits of the seven segment*/
	
	/*1- (num%10 & 0b00000111): Get the value of bits 0,1,2 of the num*/
	/*2- ((num%10 & 0b00001000) << 1): Get the value of bit 3 of the num, then shift it 1 position to left side*/
	/*3- Do OR operation to set the result from 1 into the result from 2, then set the final result to the PORTB*/
	PORTB |= (((num & 0b00001000) << 1) | (num & 0b00000111)); /*Display the num on seven segment*/
}

