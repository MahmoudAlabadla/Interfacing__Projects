/*
 * UART__Init.h

 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#ifndef UART__INIT_H_
#define UART__INIT_H_

#define UDR   *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)

void UART_Init(void);
void UART_SendData (u8 Data);
u8 UART_ReceiveData (void);

#endif /* UART__INIT_H_ */
