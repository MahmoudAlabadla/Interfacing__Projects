/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Ext_Int_Init.h"


void main(void)
{

	Dio_SetPinDirection(DDRC, PIN2, OUTPUT);

	ExtInt_Init();


	while (1){

	}



}
