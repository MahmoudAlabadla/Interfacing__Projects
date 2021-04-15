/*
 * SPI_Prog.c
 *
 *  Created on: 2021
 *      Author: Mahmoud Ayman
 */


#include "Std_Types.h"
#include "Utilites.h"
#include "SPI_Init.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"

void SPI_MasterInit (void){


	//Selecting PINS Directions for Master
	Dio_SetPinDirection(GroupB, PIN4, OUTPUT);		// SS
	Dio_SetPinDirection(GroupB, PIN5, OUTPUT);		// MOSI
	Dio_SetPinDirection(GroupB, PIN6, INPUT);		// MISO
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT);		// SCK

	//Select Master
	SET_BIT(SPCR, 4);

	//enable SPI
	SET_BIT(SPCR, 6);

	//Selecting Polarity
	//default

	//Selecting CLK Rate Frequency
	//default
}

void SPI_SlaveInit (void){

	//Selecting PINS Directions for Master
	Dio_SetPinDirection(GroupB, PIN4, INPUT);		// SS
	Dio_SetPinDirection(GroupB, PIN5, INPUT);		// MOSI
	Dio_SetPinDirection(GroupB, PIN6, OUTPUT);		// MISO
	Dio_SetPinDirection(GroupB, PIN7, INPUT);		// SCK

	//Select Slave
	CLR_BIT(SPCR, 4);

	//enable SPI
	SET_BIT(SPCR, 6);

	//Selecting Polarity
	//default

	//Selecting CLK Rate Frequency
	//default

}

void SPI_SendData (u8 data){

	//Shift data into Data Register
	SPDR = data;

	//Wait for data transfer completion flag
	while (GET_BIT(SPSR, 7) == 0);
}

u8 SPI_ReceiveData (void){

	//wait for flag to be set (data received correctly)
	while (GET_BIT(SPSR, 7) == 0);

	//Shift data from Data Register
	return	(SPDR);

}
