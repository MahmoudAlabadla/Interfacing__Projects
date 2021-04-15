/*
 * Internal_Timer_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */


#include "Dio_Reg.h"
#include "Dio_Int.h"
#include "Internal_Timer_Init.h"
#include "Utilites.h"
#include "Std_Types.h"
#include "avr/interrupt.h"

u16 counter;

ISR(TIMER0_OVF_vect)
{

	counter++;

	if (counter == 7813){

		//toggle LED
		TOG_BIT(PORTC, PIN2);
		counter = 0;
		TCNT0=128;
	}

}

void Timer_Init (void){


	// Set LED DDR as OUTPUT
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);

	// Enable Global Interrupt

	SET_BIT(SREG, 7);

	//set timer initial value

	TCNT0=128;

	// Configurations for Timer as Time Based			(0 1 0) CLK/8(from prescaler)

	CLR_BIT(TCCR0, PIN0);
	SET_BIT(TCCR0, PIN1);
	CLR_BIT(TCCR0, PIN2);

	//Enable Overflow Interrupt
	SET_BIT(TIMSK, PIN0);
}



