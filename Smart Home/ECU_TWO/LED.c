/*
 * LED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */
#include "Std_Types.h"
#include "Dio_Int.h"
#include "Utilities.h"
#include "LED.h"
#include "Dio_Reg.h"
#include "SPI_Init.h"


u8 Data = 0; // Global Variable Used to Store Received Data


											//Step 1 : DIO function for setting PIN direction and, SPI_Slave Enable

void Init_ECU2(void){

	// Using DIO Driver, Enabling the PINS connected to LEDS, as Output.
	Dio_SetPinDirection(GroupC, PIN0, OUTPUT);
	Dio_SetPinDirection(GroupC, PIN1, OUTPUT);

	// This function should Initialize the ECU2 as a Slave to Recieve the data Transimitted From the Master ECU1
	SPI_SlaveInit();
	}

											//Step 2 : Function for receiving transmitted data from Master
void Capture_Data (void){

	// Receive transmitted data Using SPI ECU2 (Slave) from  ECU1 SPI (Master)
	Data = SPI_ReceiveData();
}


											//Step 3.1 : DIO function For Toggling the LED_RED

void Check_COND_LED_RED (void){

	// Using the Data variable which stores the received data from the Master, check for condition

	if (Data == 'A'){

		TOG_BIT(PORTC, PIN0);		//Change the current state of LED_RED

	}else{
		//Do nothing
	}
}

											//Step 3.2 : DIO function For Toggling the LED_RED

void Check_COND_LED_BLUE (void){

	if (Data == 'B'){

		TOG_BIT(PORTC, PIN1);

	} else{
		//Do nothing
	}
}


