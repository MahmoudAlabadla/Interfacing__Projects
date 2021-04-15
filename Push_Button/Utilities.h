/*
 * Utilites.h
 *
 *  Created on: Sep 7, 2018
 *      Author: Mohamed
 */

#ifndef UTILITES_H_
#define UTILITES_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* UTILITES_H_ */
