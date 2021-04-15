/*
 * Terminal.c
 *
 *  Created on: 24/03/2021
 *      Author: Mahmoud Ayman
 *
 */

#include "Std_Types.h"
#include "Terminal.h"
#include "SPI_Init.h"
#include "UART__Init.h"


u8 Data = 0; //Global Variable, Used to Store Data to be Transmitted


										// Step 1: Enable UART, Initialize ECU1 as Master

void Init_ECU1 (void){

	UART_Init();		// This function enable UART
	SPI_MasterInit();   // This function should Initialize the ECU1 as a Master to Transmit data to ECU2 (Slave)
}



										// Step 2: Receive Data Using UART from Virtual Terminal

void Receive_From_Terminal (void){

	Data = UART_ReceiveData();	// This Function receives the data written into the Virtual Terminal and stores it into the Global Variable Data


	// Additional Step, verify data by sending it to second Virtual Terminal, Using UART
	UART_SendData(Data);
}



										// Step 3: Send data to the Slave (ECU2)

void Send_Data (void){

	SPI_SendData(Data);	// Transmit data using SPI_Master (ECU1) To  SPI_Slave (ECU2)
}
