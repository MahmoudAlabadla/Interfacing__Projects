/*

 * main.c
 *
 *  Created on: 24/03/2021
 *      Author: Mahmoud Ayman
 */

#include "Terminal.h"



void main (void){

	Init_ECU1 ();

	while (1){

		Receive_From_Terminal ();

		Send_Data ();
	}
}
