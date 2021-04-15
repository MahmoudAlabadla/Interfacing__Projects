/*
 * ADC_Init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mahmoud
 */
#include "Std_Types.h"

#ifndef ADC_INIT_H_
#define ADC_INIT_H_

#define ADMUX *((u8 volatile*)0x27)
#define ADCSRA *((u8 volatile*)0x26)
#define ADCL *((u8 volatile*)0x24)
#define ADCH *((u8 volatile*)0x25)


void ADC_Init(void);
u16 ADC_Read(void);

#endif /* ADC_INIT_H_ */
