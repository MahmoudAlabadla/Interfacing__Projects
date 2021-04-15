/*
 * Ext_Int_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */


#include "Ext_Int_Init.h"
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "avr/interrupt.h"

ISR(INT0_vect)
{
	// TOGGLE LED
	TOG_BIT(PORTC, 2);
}


void ExtInt_Init(void){

	//Set GIE PIN
	SET_BIT(SREG,PIN7);

	//Set PIE pin

	SET_BIT(GICR, PIN6);

	//Configure PIN mode (falling edge  , rising edge  OR change) (when will the PIF be enabled?)
	SET_BIT(MCUCR, PIN1);		// ISC01
	//CLR_BIT(MCUCR, PIN0);		// ISC00

}
