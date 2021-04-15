/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mahmoud
 */

# include <avr/delay.h>
# include "STd_Types.h"
# include "Utilities.h"
# include "DIO_Reg.h"




void main (void)
{

//	DDRC = 0x84;
//	DDRD = 0x08;


	SET_BIT(DDRC, 2);
	SET_BIT(DDRC, 7);
	SET_BIT(DDRD, 3);


		while (1){

			PORTC = 0x04; // LED 0 in portC.2 is ON
			_delay_ms(500);
			PORTC = 0x00;
	//	_delay_ms(3000);

			PORTC = 0x80; // LED 1 in portC.7
			_delay_ms(500);
			PORTC = 0x00;

			PORTD = 0x08; // LED 2 in portD.3
			_delay_ms(500);
			PORTD = 0x00;

	}
}


