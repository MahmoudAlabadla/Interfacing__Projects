/*
 * Internal_Timer_Init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */
#include "Std_Types.h"

#ifndef INTERNAL_TIMER_INIT_H_
#define INTERNAL_TIMER_INIT_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define SREG  *((volatile u8*)0x5F)

void Timer_Init(void);

#endif /* INTERNAL_TIMER_INIT_H_ */
