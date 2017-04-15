/*
 * khsie003_amalu001_lab1_part2.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * Lab 1 Exercise 2
 * Parking Space Sensor 
 * Created: 1/6/2015 7:37:38 PM
 *  Author: student
 * I acknowledge all content contained herein, excluding template or example code,
 * is my own original work.
 */ 



#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned b){
	return(b?x|(0x01<<k):x&~(0x01<<k));
}

unsigned char GetBit(unsigned char x, unsigned char k){
	return((x&(0x01<<k))!=0);
}


int main(void)
{
	DDRA = 0X00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char cntavail = 0x00;
    while(1)
    {
		//get PinA 0-3
		//if(true) cnt--;
		//else nothing!?
		cntavail = 0x00;
		if( !(PINA & 0x01))
			cntavail++;
		if( !(PINA & 0x02))
			cntavail++;
		if( !(PINA & 0x04))
			cntavail++;
		if( !(PINA & 0x08))
			cntavail++;
		PORTC = cntavail;
    }
	return 0;
}