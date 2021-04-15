/*
 * ADC_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "ADC_Init.h"
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"



void ADC_Init(void){

//	Dio_SetPinDirection(GroupA, PIN1, INPUT); is this required ?????

	//Select Voltage Reference
	SET_BIT(ADMUX, PIN6);
	CLR_BIT(ADMUX, PIN7);

	// Right Adjust
	CLR_BIT(ADMUX, PIN5);

	// Selecting Channel 0
	CLR_BIT(ADMUX, PIN0);
	CLR_BIT(ADMUX, PIN1);
	CLR_BIT(ADMUX, PIN2);
	CLR_BIT(ADMUX, PIN3);
	CLR_BIT(ADMUX, PIN4);


	// ADC Enable
	SET_BIT(ADCSRA, PIN7);

	// ADC prescaler select 8 (011)
	SET_BIT(ADCSRA, PIN0);
	SET_BIT(ADCSRA, PIN1);
	CLR_BIT(ADCSRA, PIN2);
}

u16 ADC_Read(void){

	u16 Digital_low_value, Digital_high_value;

	//Start Conversion
	SET_BIT(ADCSRA, PIN6);

	//wait until the conversion is finished
	while (GET_BIT(ADCSRA, PIN4) == 0); // the ADC will convert the flag when it finishes

	// clearing the flag after it has been used by the ADC
	SET_BIT(ADCSRA, PIN4); // this will get a value of 1 to the hardware logic gate and it will clear the flag into 0;

	//return the counter value made off 10 bits, divided within the ADCL and ADCH registers, the division is done according to chosen adjust.

	Digital_low_value = ((u16)ADCL);
	Digital_high_value = (((u16)(ADCH))<<8);

	return (Digital_high_value|Digital_low_value);


}


