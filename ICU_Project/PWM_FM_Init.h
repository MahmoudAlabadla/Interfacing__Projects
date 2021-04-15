/*
 * PWM_FM_Init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#ifndef PWM_FM_INIT_H_
#define PWM_FM_INIT_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define OCR0  *((volatile u8*)0x5C)

void Timer_Init_Fast_PWM(void);


#endif /* PWM_FM_INIT_H_ */
