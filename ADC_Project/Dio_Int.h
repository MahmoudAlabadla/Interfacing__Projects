/*
 * Dio_Int.h
 *
 *  Created on: Oct 30, 2020
 *      Author: Mohamed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "Dio_Int.h"
#include "Std_Types.h"

void Dio_SetPinDirection(u8 GroupNo, u8 PinNo, u8 Direction);
void Dio_SetPinValue(u8 GroupNo, u8 PinNo, u8 Value);
u8 Dio_GetPinValue(u8 GroupNo, u8 PinNo);

#define GroupA 0
#define GroupB 1
#define GroupC 2
#define GroupD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW   0
#define HIGH  1
#endif /* DIO_INT_H_ */
