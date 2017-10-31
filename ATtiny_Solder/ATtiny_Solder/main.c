/*
 * ATtiny_Solder.c
 *
 * Created: 25/10/2017 20:15:39
 * Author : fille
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <stdint.h>       // needed for uint8_t
#include <util/delay.h>


void controlSpeed(int Mode) 
{
	switch(Mode) {
		case 0:
			PORTB = 0b00001001;
			_delay_us(0);
			PORTB = 0b00000000;
			_delay_us(100);
			break;
		case 1: 
			PORTB = 0b00001001;
			_delay_us(20);
			PORTB = 0b00000000;
			_delay_us(80);
			break;
		case 2:
			PORTB = 0b00001001;
			_delay_us(40);
			PORTB = 0b00000000;
			_delay_us(60);
			break;
		case 3:
			PORTB = 0b00001001;
			_delay_us(60);
			PORTB = 0b00000000;
			_delay_us(40);
			break;
		case 4:
			PORTB = 0b00001001;
			_delay_us(80);
			PORTB = 0b00000000;
			_delay_us(20);
			break;
		case 5:
			PORTB = 0b00001001;
			_delay_us(100);
			PORTB = 0b0000000;
			_delay_us(0);
			break;
				
	}
}


int main(void)
{
	int Variabel = 0;
	DDRB = 0b00010000;
	while (1)
	{
		_delay_ms(500);
		if ((PINB & (1<<PB4)) != 0) {
			PORTB = 0b00001001;
			_delay_ms(100000);
		}
		else {
			PORTB = 0;
		}
		/*
		if ((PINB & (1<<PB4)) != 0) {
			Variabel++;
			_delay_ms(1000);
			if (Variabel == 6) {
				Variabel = 0;
			}
			
		}
		if (Variabel == 0) {
			controlSpeed(0);
		}
		else if (Variabel == 1) {
			controlSpeed(1);
		}
		else if (Variabel == 2) {
			controlSpeed(2);
		}
		else if (Variabel == 3) {
			controlSpeed(3);
		}
		else if (Variabel == 4) {
			controlSpeed(4);
		}
		else if (Variabel == 5) {
			controlSpeed(5);
		}
		*/
	}
}

