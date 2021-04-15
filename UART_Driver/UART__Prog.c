/*
 * UART__Prog.c

 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#include "Std_Types.h"
#include "UART__Init.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilites.h"


void UART_Init(void){

	//Enable RX and TX
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	//Selecting Asynchronous Mode
	SET_BIT(UCSRC, 7);
	CLR_BIT(UCSRC, 6);
	CLR_BIT(UCSRC, 7);

	//Selecting 1 stop bit
	CLR_BIT(UCSRC, 3);

	// No Parity mode (default)

	//Choosing Data size (8 bit)
	SET_BIT(UCSRC, 0);
	SET_BIT(UCSRC, 1);

	//Selecting 9600 BaudRate for 16 MHz frequency
	UBRRL = 103;
}

void UART_SendData(u8 Byte){

	while (GET_BIT(UCSRA, 6) == 0);
	UDR = Byte;

}

u8 UART_ReceiveData (void){

	while (GET_BIT(UCSRA, 7) == 1);
	u8	Byte = UDR;

	return (Byte);
}
