/*
 * clc.c
 *
 * Created: 4/10/2023 11:59:30 PM
 *  Author: hp
 */ 
#include "clc.h"
int getnum(int ch){
	int num=0;
	switch(ch)
	{
		
		case 0:
		num=7;
		break;
		
		case 1:
		num=8;
		break;
		
		case 2:
		num=9;
		break;
		
		case 4:
		num=4;
		break;
		
		case 5:
		num=5;
		break;
		
		case 6:
		num=6;
		break;
		
		//case 7:
		//num=7;
		//break;
		
		case 8:
		num=1;
		break;
		
		case 9:
		num=2;
		break;
		
		case 10:
		num=3;
		break;
		case 11:
		lcd_clear();
		case 13:
		num=0;
		break;
		case 12:
		lcd_clear();
		break;
		default:
		num=13;
		
		
	}
	return num;
}
