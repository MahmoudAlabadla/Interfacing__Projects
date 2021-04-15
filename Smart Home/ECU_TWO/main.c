/*
 * main.c
 *
 *  Created on: 24/03/2021
 *      Author: Mahmoud Ayman
 */


#include "LED.h"

 void main (void){

	Init_ECU2();

	while (1){

		Capture_Data();

		Check_COND_LED_RED();

		Check_COND_LED_BLUE();

	}

}
