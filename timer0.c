/*
 * timer0.c
 *
 * Created: 4/29/2023 11:14:08 AM
 *  Author: Lab2
 */ 
#include "timer0.h"
#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "std_types.h"

#define I_BIT 7
void(*g_calbackptr)(void)=NULL_PTR;
ISR(TIMER0_OVF_vect)
{
	if(g_calbackptr !=NULL_PTR)
	
	{
		(*g_calbackptr)();
	}

	
}
void TIMER0_init()
{
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);
	SET_BIT(SREG,I_BIT);	

}
void timer0_setcalback(void(*a_ptr)(void))
{
	g_calbackptr=a_ptr;
	
	
}
