/*
 * main.c
 *
 *  Created on: Oct 30, 2020
 *      Author: Mohamed
 */

#include "Dio_Reg.h"
#include "Utilites.h"
#include "util/delay.h"
#include "LCD_Init.h"


void main(void)
{
	LCD_Init();
	LCD_WriteCommand(0b10001111);
	LCD_WriteWord("Mohamed");
	LCD_WriteCommand(0b11000000);
	LCD_WriteWord("Abdelatiff");

	while(1)
     {

     }
}
