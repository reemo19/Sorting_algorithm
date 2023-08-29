/*
 * timer0.h
 *
 * Created: 4/29/2023 11:11:05 AM
 *  Author: Lab2
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#define NUMBER_half_OF_OVERFLOW 31//.5 s
//#define NUMBER_half_OF_OVERFLOW 122
#define NUMBER_OF_OVERFLOW 61 //1 s
//#define NUMBER_OF_OVERFLOW 122  //2 s

void TIMER0_init();
void timer0_setcalback(void(*a_ptr)(void));
void timer0_setcalback1(void(*a_ptr)(void));

#endif /* TIMER0_H_ */