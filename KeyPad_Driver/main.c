/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#include "Dio_Reg.h"
#include "KeyPad_Interface.h"

void main (void){

	u8 var_ret;

	DDRA = 0xff;		// this enables the LEDs in Group (PORT) A  to switch on.

// DI0_set direction for DDRA group as a whole, ADD to the DIO driver

	KeyPad_Init();

	while(1){


		var_ret = KeyPad_GetKey();
		if (var_ret!=0xff)
			PORTA=var_ret;

	}

}
