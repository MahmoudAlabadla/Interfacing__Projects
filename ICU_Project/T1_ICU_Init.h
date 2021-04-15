/*
 * External_ICU_Init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#ifndef T1_ICU_INIT_H_
#define T1_ICU_INIT_H_

#define SREG 	*((volatile u8*)0x5F)
#define TCCR1A	*((volatile u8*)0x4F)
#define TCCR1B	*((volatile u8*)0x4E)
#define TCNT1H	*((volatile u8*)0x4D)
#define TCNT1L	*((volatile u8*)0x4C)
#define ICR1H	*((volatile u8*)0x47)
#define ICR1L	*((volatile u8*)0x46)
#define TIMSK	*((volatile u8*)0x59)
#define TIFR 	*((volatile u8*)0x58)

void T1_ICU_Init(void);

#endif /* T1_ICU_INIT_H_ */
