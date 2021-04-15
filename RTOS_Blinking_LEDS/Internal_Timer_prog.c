/*
 * Internal_Timer_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "Std_Types.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "Dio_Int.h"
#include "Internal_Timer_Init.h"
#include "avr/interrupt.h"
#include "OS.h"

u8 counts = 0;
extern u8 OS_Counts;

ISR(TIMER0_OVF_vect)
{

	// Timer for every 100 ms
	counts ++;
	if (counts == 98){

	OS_Counts++;
	Scheduler();
	counts = 0;
	TCNT0 = 88;
	}

}

void Timer_Init (void){

	// Enable Global Interrupt
	SET_BIT(SREG, 7);

	//set timer initial value
	TCNT0=88;

	// Configurations for Timer as Time Based			(0 1 1) CLK/64(from prescaler)
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);

	//Enable Overflow Interrupt
	SET_BIT(TIMSK, 0);
}



