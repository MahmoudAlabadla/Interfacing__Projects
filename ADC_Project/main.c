/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mahmoud
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "ADC_Init.h"
#include "LCD_Init.h"

#define locations 16
#define Clear 0x01


void main (void){

	u8 LineOne[locations] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F};
	u8 LineTwo[locations] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF};
	u8 Title [] = "Analog Value";
	u8 Unit [] = "mV";
	u32	Analog_value, Digital_value;

	//LCD Initialization
	LCD_Init();

	LCD_WriteCommand(LineOne[2]);
	LCD_WriteWord(Title);

	LCD_WriteCommand(LineTwo[8]);
	LCD_WriteWord(Unit);

	LCD_WriteCommand(LineTwo[1]);
	LCD_WriteData(0b00110111);


	//ADC Initialization
	ADC_Init();


	while(1)
	{
		// Starting ADC
		Digital_value = ADC_Read();		// values of counter returned, ones and zeros represent the analog input in digital form.


		//convert digital value into analog values
		Analog_value = (Digital_value*5*1000)/1023;


		// Represent the analog value on the LCD

		LCD_WriteCommand(LineTwo[0]);

		if (Analog_value>= 2500)
			LCD_WriteWord("A");
		else if (Analog_value<2500 && Analog_value>1500)
			LCD_WriteWord("B");
		else if (Analog_value>= 1000 && Analog_value <= 1500)
			LCD_WriteWord("C");
		else
			LCD_WriteWord("D");
	}


}
