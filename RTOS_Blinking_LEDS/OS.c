/*
 * OS.c
 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#include "STd_Types.h"
#include "Utilities.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Internal_Timer_Init.h"
#include "OS.h"

Task Arr[No_Of_Tasks];
u8 OS_Counts = 0;

void Task1 (void){

	Dio_SetPinDirection(GroupC, 2, OUTPUT);
	TOG_BIT(PORTC, 2);
}

void Task2 (void){

	Dio_SetPinDirection(GroupC, 7, OUTPUT);
	TOG_BIT(PORTC, 7);
}

void Task3 (void){

	Dio_SetPinDirection(GroupC, 3, OUTPUT);
	TOG_BIT(PORTC, 3);
}

void Create_Task (u8 Priority, u8 Periodicity, void (*FPTR)(void)){

	Arr[Priority]. Periodicity = Periodicity;
	Arr[Priority]. FPTR = FPTR;
}

void OS_init (void){

	Create_Task(0, 2, Task1);
	Create_Task(1, 4, Task2);
	Create_Task(2, 8, Task3);
}

void Scheduler (void){

	u8 i = 0;

	for (i=0; i<No_Of_Tasks; i++){

		if (OS_Counts % Arr[i].Periodicity == 0){
			Arr[i].FPTR();
		}
		else{
			//Do nothing
		}
	}
}




