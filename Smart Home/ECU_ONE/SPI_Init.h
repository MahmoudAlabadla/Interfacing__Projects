/*
 * SPI_Init.h
 *
 *  Created on: 2021
 *      Author: Mahmoud Ayman
 */

#ifndef SPI_INIT_H_
#define SPI_INIT_H_

#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)


void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_SendData(u8);
u8 SPI_ReceiveData(void);



#endif /* SPI_INIT_H_ */
