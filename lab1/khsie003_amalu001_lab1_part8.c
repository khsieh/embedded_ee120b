/* Kevin Hsieh, khsie003
* Alyza Malunao, amalu001
* Lab Section: 23
* Assignment: Lab #1 Exercise #7
* Exercise Description: Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4. That
* is to say, take the upper nibble of PINA and map it to the lower nibble of PORTB,
* likewise take the lower nibble of PINA and map it to the upper nibble of PORTC
* (PA7 -> PB3, PA6 -> PB2, … PA1 -> PC5, PA0 -> PC4).
* I acknowledge all content contained herein, excluding template or example
* code, is my own original work.
*/

#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs 
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
	
    while(1)
    {
		unsigned char PB = PORTB & 0xF0;
		unsigned char PC = PORTC & 0x0F;
		PORTB = PB | (PINA >> 4);
		PORTC = PC | (PINA << 4);
        
    }
	return 0;
}