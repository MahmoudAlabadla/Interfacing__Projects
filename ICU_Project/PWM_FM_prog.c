/*
 * PWM_FM_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "Dio_Reg.h"
#include "Dio_Int.h"
#include "PWM_FM_Init.h"
#include "Utilites.h"
#include "Std_Types.h"
#include "avr/interrupt.h"

void Timer_Init_Fast_PWM(void){


	// Configurations for Timer as Time Based with FAST_PWM

	SET_BIT(TCCR0, PIN3);		// for fast
	SET_BIT(TCCR0, PIN6);		// PWM mode


	//  CLK/8 Prescaler

	CLR_BIT(TCCR0, PIN0);
	SET_BIT(TCCR0, PIN1);
	CLR_BIT(TCCR0, PIN2);

	// NON_INVERTING Duty Cycle

	SET_BIT(TCCR0, PIN5);
	CLR_BIT(TCCR0, PIN4);

}
