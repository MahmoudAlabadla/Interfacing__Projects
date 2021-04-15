/*
 * UART__Prog.c

 *
 *  Created on: 24/03/2021
 *      Author: Mahmoud Ayman
 */
#include "Std_Types.h"
#include "UART__Init.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilities.h"



void UART_Init(void){

	SET_BIT(UCSRC, 7);

	//Enable RX and TX
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	//Selecting Asynchronous Mode
	CLR_BIT(UCSRC, 6);
	CLR_BIT(UCSRC, 7);

	//Selecting 1 stop bit
	CLR_BIT(UCSRC, 3);

	// No Parity mode (default)

	//Choosing Data size (8 bit)
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);

	//Selecting 9600 BaudRate for 16 MHz frequency
	UBRRH =0;
	UBRRL = 103;
}

void UART_SendData(u8 Byte){

	while (GET_BIT(UCSRA, 5) == 0);
	UDR = Byte;
}

u8 UART_ReceiveData (void){

	while (GET_BIT(UCSRA, 7) == 0);

	return (UDR);
}
