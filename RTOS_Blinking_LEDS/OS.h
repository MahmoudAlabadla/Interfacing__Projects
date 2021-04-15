/*
 * OS.h
 *
 *  Created on: 2021
 *      Author: Mahmoud
 */

#ifndef OS_H_
#define OS_H_

#define No_Of_Tasks 3


typedef struct{
	u8 Periodicity;
	void (*FPTR) (void);
}Task;

void Scheduler (void);
void OS_init (void);
void Create_Task (u8 Priority, u8 Periodicity, void (*FPTR) (void) );
void Task1 (void);
void Task2 (void);
void Task3 (void);


#endif /* OS_H_ */
