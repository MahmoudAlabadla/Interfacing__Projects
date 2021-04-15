/*
 * Utilites.h
 *
 *  Created on: 24/03/2021
 *      Author: Mahmoud Ayman
 */

#ifndef UTILITES_H_
#define UTILITES_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* UTILITES_H_ */
