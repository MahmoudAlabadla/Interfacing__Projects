/*
 * TWI_Init.h
 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#ifndef TWI_INIT_H_
#define TWI_INIT_H_

#define TWBR *((volatile u8*)0x)
#define TWCR *((volatile u8*)0x)
#define TWSR *((volatile u8*)0x)
#define TWDR *((volatile u8*)0x)
#define TWAR *((volatile u8*)0x22)

void I2C_Master_Init(void);
void I2C_Slave_Init(void);

void I2C_Start (void);
void I2C_RepeatedStart (void);

void I2C_Stop (void);

u8 I2C_ReadByte(void);
void I2C_WriteByte(u8);



#endif /* TWI_INIT_H_ */
