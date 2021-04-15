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
#include "Std_Types.h"

#define locations 16
#define clear 0x01

void main(void)
{

	LCD_Init();
	u8  i, j;
	u8 LineOne[locations] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F};
	u8 LineTwo[locations] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF};
	u8 Name = "Mahmoud";


	while(1)
     {

		for (i=0; i < locations; i++){

					LCD_WriteCommand(LineOne[i]);
					LCD_WriteWord(Name);

					_delay_ms(250);
					LCD_WriteCommand(clear);
				 }
				for (j=0; j < locations; j++){

						LCD_WriteCommand(LineTwo[j]);
						LCD_WriteWord(Name);
						_delay_ms(250);
						LCD_WriteCommand(clear);
					}

     }
}


