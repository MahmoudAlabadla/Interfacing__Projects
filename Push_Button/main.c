/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Twins
 */


#include "DIO_Reg.h"
#include "STd_Types.h"
#include "Utilities.h"
#include <avr/delay.h>



void main (){

	int MODE1, MODE2;
	enum Mode_Status {UNPRESSED, PRESSED};

	SET_BIT(DDRC, 2);
	SET_BIT(DDRC, 7);
	SET_BIT(DDRD, 3);
	CLR_BIT(DDRD, 2);


	while(1){



		if (GET_BIT(PIND, 2) == 0){    // Check if Not_Pressed  - Pull_Down default  is 0v

			MODE1 = 0;  // Make it work
			MODE2 = 0;	// Make it stop
		}else{
			MODE1 = 1;  // Make it stop
			MODE2 = 1;	// make it work
		}

														// Mode 1

		if (MODE1 == UNPRESSED ){

			PORTC = 0x04; // LED 0 in portC.2 is ON
			_delay_ms(500);
			PORTC = 0x00;

			PORTC = 0x80; // LED 1 in portC.7
			_delay_ms(500);
			PORTC = 0x00;

			PORTD = 0x08; // LED 2 in portD.3
			_delay_ms(500);
			PORTD = 0x00;
		}

														// Mode 2

		if (MODE2 == PRESSED) {

			PORTC = 0x80; // LED 1 in portC.7 is ON
			_delay_ms(1000);
			PORTC = 0x00;

			PORTC = 0x04; // LED 0 in portC.2 is ON
			PORTD = 0x08; // LED 2 in portD.3 is ON
			_delay_ms(500);

			PORTC = 0x00;
			PORTD = 0x00;
		}

	}
}



