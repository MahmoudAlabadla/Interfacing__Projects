/*
 * main.c
 *
 *  Created on: 17/02/2021
 *      Author: Mahmoud Alabadla
 */

#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Int.h"
#include "avr/delay.h"
#include "ADC_Init.h"
#include "LCD_Init.h"
#include "PWM_FM_Init.h"
#include "T1_ICU_Init.h"


#define locations 16
#define Clear 0x01

void main (void){

	u8 LineOne[locations] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F};
	u8 LineTwo[locations] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF};

	u8 Frequency [] = "F: ";
	u8 Freq_Sign [] = "Hz";
	u8 Duty_Cycle [] = "DC: ";
	u8 Cycle_Sign [] = "%";
	//u8 Motor_Direction = "M_D: ";
	//u8 Right [] = "Right";
	//u8 Left [] = "Left";

	u32	Analog_value, Digital_value, DC_Percentage, Ref_value = 5000;
	u8 Resolution_T0 = 256;



	/*LCD Initialization
	LCD_Init();

	//	LINE 1
	LCD_WriteCommand(LineOne[0]);
	LCD_WriteWord(Frequency);

	LCD_WriteCommand(LineOne[6]);
	LCD_WriteWord(Freq_Sign);

	LCD_WriteCommand(LineOne[9]);
	LCD_WriteWord(Duty_Cycle);

	LCD_WriteCommand(LineOne[15]);
	LCD_WriteWord(Cycle_Sign);

	//	LINE 2
	//LCD_WriteCommand(LineTwo[0]);
	//LCD_WriteWord(Motor_Direction);

	*/

	//ADC Initialization
	ADC_Init();

	//ICU Initialization
	T1_ICU_Init();

	//Start Timer IN Fast PWM Mode
	Timer_Init_Fast_PWM();

	// Set Timer0 Pin to Output
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);

	while(1){

		// start ADC0 conversion

			Digital_value = ADC_Read();

		// give the Digital value of ADC to the OCR0 register. (register for timer0 duty cycle). OCR0 can't be more than the OverFlow time of Timer0

		//convert digital value into analog values

			Analog_value = (Digital_value*5*1000)/1024;

		// Use Analog value for Re-mapping to new digital values

			DC_Percentage = ((Analog_value/Ref_value)*100);

			OCR0 = ((DC_Percentage/100)*(Resolution_T0));

		// Use ICU pin as external interrupt and calculate the the Frequency received from PWM pin

		//Edge detection/activation
			SET_BIT(TCCR1B, PIN6);		// rising edge

		// start timer1

		//set as falling edge

		// take values of TCNT1H and TCNT1L into the same u16 variable


		// Display on LCD

	}

}


/*	steps for the project

	1) Use potentiometer on ADC0  					DONE
	2) Use value coming from potentiometer to change the duty cycle of external PWM 	Done
	3) PWM (timer0) will be an output to Timer1 ICU Pin (External Interrupt)
	4) Using LCD, Display the values of frequency and duty cycle
	5) After achieving the previous, connect switch to External Interrupt Pin
		- Using 2 relays and 2 transistors, connect motor and toggle the its Direction while display on LCD as well.

		*/
