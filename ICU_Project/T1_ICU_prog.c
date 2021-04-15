/*
 * External_ICU_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilites.h"
#include "Std_Types.h"
#include "T1_ICU_Init.h"


ISR(TIMER1_OVF_vect){

	//Ton equals ICR1

	u16 count;

	count ++;
	if (count == ){

		//Do something

		//clear ICF1
		SET_BIT(TIFR, PIN5);
	}
}


void T1_ICU_Init(void){

	//enable global interrupt
	SET_BIT(SREG, PIN7);

	// I/O pin direction as input
	Dio_SetPinDirection(GroupD, PIN6, INPUT);

	// PWM MODE Select ICR1 first 2 bit in both TCCR1A and TCCR1B (1,1,1,0)
	CLR_BIT(TCCR1A, PIN0);
	SET_BIT(TCCR1A, PIN1);

	SET_BIT(TCCR1B, PIN3);
	SET_BIT(TCCR1B, PIN4);

	//Enable ICF1 ?

	// Enable Noise cancellation
	SET_BIT(TCCR1B, PIN7);



	// Pre-scaller 8 select ( 0 1 0) for pins (2 1 0)
	SET_BIT(TCCR1B, PIN1);

	// Interrupt Input capture flag Enable (enable overflow)
	SET_BIT(TIMSK, PIN5);

	//enable ICU interrupt
	SET_BIT(TIFR, PIN5);



}
