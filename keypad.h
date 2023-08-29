#ifndef KEYPAD_H_
#define KEYPAD_H_


#define F_CPU 16000000
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "LCD.h"
#include <util/delay.h>
#define F_CPU 16000000
#define INVALID_KEYPAD_PRESS (0xFF)
unsigned char keypress(void);
void keypad_Init();
unsigned char keypad_get_value();
char keypadd(void);
#endif /*keypad*/

