/*
 * TWI_Prog.c
 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "TWI_Init.h"

void I2C_Master_Init(void){

	// Selecting Clock Frequency for Master Mode
	TWBR = 0x03;

	// Setting Pre-scaler to 1  (default
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);

	//Enabling I2C
	SET_BIT(TWCR, 2);
}

void I2C_Slave_Init(void){

	//Provide a slave address, for example 0x01
	TWAR = 0x08;
	//Enable I2C
	SET_BIT(TWCR, 2);
}

void I2C_Start (void){

	// Clear TWI interrupt flag
	SET_BIT(TWCR, 7);

	// Put Start Condition on SDA
	SET_BIT(TWCR, 5);

	// Enable TWI
	SET_BIT(TWCR, 2);

	// Wait till start condition transmitted ( check the interrupt flag)
	while (GET_BIT(TWCR, 7));

	//( check the Status Register)
	while ((TWSR&0xF8)!=0x08);
}

void I2C_RepeatedStart (void){

	// Clear TWI interrupt flag
	SET_BIT(TWCR, 7);

	// Put Start Condition on SDA
	SET_BIT(TWCR, 5);

	// Enable TWI
	SET_BIT(TWCR, 2);

	// Wait till start condition transmitted ( check the interrupt flag)
	while (GET_BIT(TWCR, 7));

	//( check the Status Register)
	while ((TWSR&0xFA)!=0x0A);
}

void I2C_Stop (void){

	// Clear TWI interrupt flag
	SET_BIT(TWCR, 7);

	//Stop Condition
	CLR_BIT(TWCR, 4);

	// Enable TWI
	SET_BIT(TWCR, 2);
}

void I2C_WriteByte(u8 data){

	// Put data in Data Register
	TWDR = data;

	// Clear TWI interrupt flag
	SET_BIT(TWCR, 7);

	// Enable TWI
	SET_BIT(TWCR, 2);

	// Check for Acknowledgment
	while ((TWSR&0xF8)!=0x28);
}

u8 I2C_ReadByte(void){

	// Clear TWI interrupt flag
		SET_BIT(TWCR, 7);

	// Enable TWI
	SET_BIT(TWCR, 2);

	//Wait till complete TWDR byte transmitted
	while (GET_BIT(TWCR, 7)!=0);

	// Check for Acknowledgment
	while ((TWSR&0xF8)!=0x58);

	// return data
	return (TWDR);
}
