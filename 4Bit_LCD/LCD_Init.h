/*
 * LCD_Int.h
 *
 *  Created on: Oct 31, 2020
 *      Author: Mohamed
 */

#ifndef LCD_INIT_H_
#define LCD_INIT_H_

#include "Std_Types.h"


void LCD_Init(void);

void LCD_WriteCommand(u8 Command);
void LCD_WriteData(u8 Data);
void LCD_WriteWord(u8 *Word);

#endif /* LCD_INIT_H_ */
