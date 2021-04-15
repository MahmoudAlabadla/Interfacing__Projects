/*
 * Ext_Int_Init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */

#ifndef EXT_INT_INIT_H_
#define EXT_INT_INIT_H_

#define SREG *((u8 volatile*)0x5F)
#define GICR *((u8 volatile*)0x5B)
#define MCUCR *((u8 volatile*)0x55)

void ExtInt_Init (void);

#endif /* EXT_INT_INIT_H_ */
