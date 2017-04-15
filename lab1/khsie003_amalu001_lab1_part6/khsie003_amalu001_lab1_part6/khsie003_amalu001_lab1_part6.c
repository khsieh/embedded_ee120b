/**
 * khsie003_amalu001_lab1_part4.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * Lab 1 Exercise 5
 * In addition to the above, PA4 is 1 if a key is in the ignition, PA5 is 1 if a driver is
 * seated, and PA6 is 1 if the driver's seatbelt is fastened. PC7 should light a "Fasten
 * seatbelt" icon if a key is in the ignition, the driver is seated, but the belt is not
 * fastened.
 * Note: A port can be set to be input for some pins, and output for other pins by setting the
 * DDR appropriately, e.g. DDRA = 0xF0; will set port A to output on the high nibble, and
 * input on the low nibble.
 * Created: 1/6/2015 7:37:38 PM
 *  Author: student
 * I acknowledge all content contained herein, excluding template or example code,
 * is my own original work.
 */ 

#include <avr/io.h>

//x is the word to be modified, k-th bit to modify, b is the new bit
unsigned char SetBit(unsigned char x, unsigned char k, unsigned b){
	return(b?x|(0x01<<k):x&~(0x01<<k));
}

int main(void)
{
	unsigned char lights = 0;
	unsigned char PA = 0;
	DDRA = 0x00; PORTA = 0xFF; 
	DDRC = 0xFF; PORTC = 0x00;
	
    while(1)
    {
        PA = PINA & 0x0F;
		lights = 0;
		lights = SetBit(lights, 0, PA >= 13);
		lights = SetBit(lights, 1, PA >= 10);
		lights = SetBit(lights, 2, PA >= 7);
		lights = SetBit(lights, 3, PA >= 5);
		lights = SetBit(lights, 4, PA >= 3);
		lights = SetBit(lights, 5, PA >= 1);
		lights = SetBit(lights, 6, PA <= 4);
		lights = SetBit(lights, 7, (PINA & 0x70) & 0x30);
		PORTC = lights;
    }
	return 0;
}