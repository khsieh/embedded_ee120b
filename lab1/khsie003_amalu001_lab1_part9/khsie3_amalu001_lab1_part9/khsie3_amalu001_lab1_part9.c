/**
 * khsie003_amalu001_lab1_part4.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * Lab 1 Exercise 9
 * A car's passenger-seat weight sensor outputs a 9-bit value (ranging from 0 to 511)
 * and connects to input PD7..PD0PB0 on the microcontroller. If the weight is equal
 * to or above 70 pounds, the airbag should be enabled by setting PB1 to 1. If the
 * weight is above 5 but below 70, the airbag should be disabled and an "Airbag
 * disabled" icon should light by setting PB2 to 1. (Neither B1 nor B2 should be set if
 * the weight is 5 or less, as there is no passenger).
 * Created: 1/6/2015 7:39:38 PM
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
	DDRB = 0xFE; PORTB = 0x00; // output
	DDRD = 0x00; PORTD = 0x00; //input
	
	
    while(1)
    {
		unsigned char tempB = PORTB;
        if(PIND >= 35)
		{
			tempB = SetBit(tempB, 1, 1);
		}
		else
		{
			tempB = SetBit(tempB,1,0);
		}
		if((PIND > 2) && (PIND < 35))
		{
			tempB = SetBit(tempB, 2, 1);
		}
		else//(PIND <= 2)
		{
			tempB = SetBit(tempB,2,0);
		}
		PORTB = tempB;
    }
	return 0;
}