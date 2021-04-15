/*

 * main.c
 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#include "Std_Types.h"

#include "UART__Init.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilites.h"


void main (void){

	UART_Init();

	while (1){

		u8 x = UART_ReceiveData();

		UART_SendData(x);

	}

}
