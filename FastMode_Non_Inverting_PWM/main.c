/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "PWM_FM_Init.h"
#include "Dio_Reg.h"
#include "Dio_Int.h"
#include "Utilites.h"
#include "avr/delay.h"
#include "Std_Types.h"

void main (void){

	Timer_Init_Fast_PWM();							//for starting timer once.
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);		// for enabling the timer output pin. (OC0)

	while(1){

		// 25% Duty_Cycle 64

		OCR0 = 0b01000000;
		_delay_ms(3000);		// 3 seconds delay


		// 50% Duty_Cycle 127

		OCR0 = 0b10000000;
		_delay_ms(3000);


		// 75% Duty_Cycle 191

		OCR0 = 0b11000000;
		_delay_ms(3000);

	}
}
