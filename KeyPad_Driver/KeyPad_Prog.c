/*
 * KeyPad_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"

void KeyPad_Init(void){

// Initialize input PINs

	Dio_SetPinDirection( GroupC, PIN3, INPUT);	// setting Row 1
	Dio_SetPinDirection( GroupC, PIN4, INPUT);	// setting Row 2
	Dio_SetPinDirection( GroupC, PIN5, INPUT);	// setting Row 3
	Dio_SetPinDirection( GroupC, PIN6, INPUT);	// setting Row 4


// Define the input to be pull up

	Dio_SetPinValue(GroupC, PIN3, HIGH);
	Dio_SetPinValue(GroupC, PIN4, HIGH);
	Dio_SetPinValue(GroupC, PIN5, HIGH);		// 1 for Internal  PULL_UP
	Dio_SetPinValue(GroupC, PIN6, HIGH);

// define the output pins

	Dio_SetPinDirection(GroupC,  PIN0,  OUTPUT); 	 // setting column 1
	Dio_SetPinDirection(GroupC,  PIN1,  OUTPUT); 	 // setting column 2
	Dio_SetPinDirection(GroupC,  PIN2,  OUTPUT);	 // setting column 3

}

u8 KeyPad_GetKey (void){

	u8 return_var;
	// First Iteration  0 , 1 , 1 FOR the OUTPUTs Columns


	Dio_SetPinValue(GroupC, PIN0, LOW);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2, HIGH);

	if (Dio_GetPinValue(GroupC, PIN3) ==  LOW)
		return_var =1;
	if (Dio_GetPinValue(GroupC, PIN4) ==  LOW)
		return_var =4;
	if (Dio_GetPinValue(GroupC, PIN5) ==  LOW)
		return_var =7;
	if (Dio_GetPinValue(GroupC, PIN6) ==  LOW)
		return_var ='*';

	// Second Iteration

	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, LOW);
	Dio_SetPinValue(GroupC, PIN2, HIGH);

	if (Dio_GetPinValue(GroupC, PIN3) ==  LOW)
		return_var =2;
	if (Dio_GetPinValue(GroupC, PIN4) ==  LOW)
		return_var =5;
	if (Dio_GetPinValue(GroupC, PIN5) ==  LOW)
		return_var =8;
	if (Dio_GetPinValue(GroupC, PIN6) ==  LOW)
		return_var = 0;

	// Third Iteration


	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2, LOW);

	if (Dio_GetPinValue(GroupC, PIN3) ==  LOW)
		return_var =3;
	if (Dio_GetPinValue(GroupC, PIN4) ==  LOW)
		return_var =6;
	if (Dio_GetPinValue(GroupC, PIN5) ==  LOW)
		return_var =9;
	if (Dio_GetPinValue(GroupC, PIN6) ==  LOW)
		return_var ='#';

	return return_var;
}
