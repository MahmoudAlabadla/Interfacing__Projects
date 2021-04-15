/*
 * LCD_Prog.c
 *
 *  Created on: Oct 31, 2020
 *      Author: Mohamed
 */


#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "util/delay.h"
#include "Std_Types.h"
#include "LCD_Init.h"

void LCD_Init(void)
{
	//RS c0
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);
	//RW
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);
	//E
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);

	//data lines (4bit mode)
	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);


		_delay_ms(100);
		LCD_WriteCommand(0b00000010);

		LCD_WriteCommand(0b00101000);

		LCD_WriteCommand(0b00001100);

		LCD_WriteCommand(0b00000110);

		LCD_WriteCommand(0b00000001);

	/*
	 *
	 *
	 * _delay_ms(100);
	LCD_WriteCommand(0x02);//send for 4 bit initialization of LCD
	LCD_WriteCommand(0x28);//Function set command: 2 line, 5*7 matrix in 4-bit mode
	LCD_WriteCommand(0x0C);//display on, curser of
	LCD_WriteCommand(0x06);//entry mode set: shift curser
	LCD_WriteCommand(0x01);//clear Display

	///////////


	_delay_ms(100);
		LCD_WriteCommand(0b00100000);		//function set
		_delay_ms(5);
		LCD_WriteCommand(0b00100000);		//4 bit mode
		_delay_ms(1);
		LCD_WriteCommand(0b11000000);		//3x commands

		_delay_ms(1);
		LCD_WriteCommand(0b00000000);		//display on/off setting
		_delay_ms(1);
		LCD_WriteCommand(0b11100000);

		_delay_ms(1);
		LCD_WriteCommand(0b00000000);		//display clear
		_delay_ms(1);
		LCD_WriteCommand(0b00010000);

		_delay_ms(1);
		LCD_WriteCommand(0b00000000);		//entry mode set
		_delay_ms(1);
		LCD_WriteCommand(0b01100000);
		_delay_ms(1);

*/
}

void LCD_WriteCommand(u8 Command)
{
	//RS low
	Dio_SetPinValue(GroupB, PIN1, LOW);
	//RW low
	Dio_SetPinValue(GroupB, PIN2, LOW);

	// Taking Hightest bits
	PORTA = (PORTA&0x0F)|(Command&0xF0);

	//set enable pin high
	Dio_SetPinValue(GroupB, PIN3, HIGH);
	_delay_ms(1);
	//set enable pin low
	Dio_SetPinValue(GroupB, PIN3, LOW);
	_delay_ms(5);


	// Taking lowest bits

	PORTA = (PORTA&0x0F)|((Command)<<4);

	//set enable pin high
	Dio_SetPinValue(GroupB, PIN3, HIGH);
	_delay_ms(1);
	//set enable pin low
	Dio_SetPinValue(GroupB, PIN3, LOW);
	_delay_ms(5);

}


void LCD_WriteData(u8 Data)
{
	//RS high
	Dio_SetPinValue(GroupB, PIN1, HIGH);
	//RW LOW == Write
	Dio_SetPinValue(GroupB, PIN2, LOW);

	// taking highest bits
	PORTA = (PORTA&0x0F)|(Data&0xF0);
	//set enable pin high
	Dio_SetPinValue(GroupB, PIN3, HIGH);
	_delay_ms(1);
	//set enable pin low
	Dio_SetPinValue(GroupB, PIN3, LOW);
	_delay_ms(5);


	// taking lowest bits
	PORTA = (PORTA&0x0F)|(Data<<4);
	//set enable pin high
	Dio_SetPinValue(GroupB, PIN3, HIGH);
	_delay_ms(1);
	//set enable pin low
	Dio_SetPinValue(GroupB, PIN3, LOW);
	_delay_ms(5);
}

void LCD_WriteWord(u8 *Word)
{
	u8 index=0;
	while(Word[index]!='\0')
	{
		LCD_WriteData(Word[index]);
		index++;
	}
}












