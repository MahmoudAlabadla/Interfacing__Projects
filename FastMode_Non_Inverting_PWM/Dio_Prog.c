/*
 * Dio_Prog.c
 *
 *  Created on: Oct 30, 2020
 *      Author: Mohamed
 */
#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"
#include "Utilites.h"

void Dio_SetPinDirection(u8 GroupNo, u8 PinNo, u8 Direction)
{
	if((GroupNo<=GroupD) && (PinNo<=PIN7))
	{
		if(Direction==OUTPUT)
		{
			switch(GroupNo)
			{
			case GroupA: SET_BIT(DDRA, PinNo); break;
			case GroupB: SET_BIT(DDRB, PinNo); break;
			case GroupC: SET_BIT(DDRC, PinNo); break;
			case GroupD: SET_BIT(DDRD, PinNo); break;
			}
		}
		else if(Direction==INPUT)
		{
			switch(GroupNo)
			{
			case GroupA: CLR_BIT(DDRA, PinNo); break;
			case GroupB: CLR_BIT(DDRB, PinNo); break;
			case GroupC: CLR_BIT(DDRC, PinNo); break;
			case GroupD: CLR_BIT(DDRD, PinNo); break;
		    }
	    }
		else
		{
			//wrong Direction do noting
		}
	}
}
void Dio_SetPinValue(u8 GroupNo, u8 PinNo, u8 Value)
{
	if((GroupNo<=GroupD) && (PinNo<=PIN7))
		{
			if(Value==LOW)
			{
				switch(GroupNo)
				{
				case GroupA: CLR_BIT(PORTA, PinNo); break;
				case GroupB: CLR_BIT(PORTB, PinNo); break;
				case GroupC: CLR_BIT(PORTC, PinNo); break;
				case GroupD: CLR_BIT(PORTD, PinNo); break;
				}
			}
			else if(Value==HIGH)
			{
				switch(GroupNo)
				{
				case GroupA: SET_BIT(PORTA, PinNo); break;
				case GroupB: SET_BIT(PORTB, PinNo); break;
				case GroupC: SET_BIT(PORTC, PinNo); break;
				case GroupD: SET_BIT(PORTD, PinNo); break;
			    }
		    }
			else
			{
				//wrong Direction do noting
			}
		}
}
u8 Dio_GetPinValue(u8 GroupNo, u8 PinNo)
{
	u8 Ret_PinValue=0;

	if((GroupNo<=GroupD) && (PinNo<=PIN7))
	{
		switch(GroupNo)
		{
		case GroupA: Ret_PinValue=GET_BIT(PINA, PinNo); break;
		case GroupB: Ret_PinValue=GET_BIT(PINB, PinNo); break;
		case GroupC: Ret_PinValue=GET_BIT(PINC, PinNo); break;
		case GroupD: Ret_PinValue=GET_BIT(PIND, PinNo); break;
		}
	}
	else
		Ret_PinValue=0xFF;

return Ret_PinValue;
}
