/*
 * IncFile1.h
 *
 * Created: 4/10/2023 11:55:27 PM
 *  Author: hp
 */ 


#ifndef clc_H_
#define clc_H_


#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "LCD.h"
#include <util/delay.h>
int getnum(int);
void dispnum(int);
unsigned char get_func(unsigned char chf) ;

#endif /* INCFILE1_H_ */