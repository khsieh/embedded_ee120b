/*
 * khsie003_amalu001_lab1_part2.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * Lab 1 Exercise 1
 * Garage open at Night 
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

//x is the word to access, k-th bit to get
unsigned char GetBit(unsigned char x, unsigned char k){
	return((x&(0x01<<k))!=0);
}

int main(void)
{
	DDRA = 0X00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
	
	unsigned char tmpB = 0x00;
	unsigned char openDark = 0x00;
    while(1)
    {
        //TODO:: Please write your application code
		openDark = (GetBit(PINA,0) & ~GetBit(PINA,1));
		tmpB = SetBit(tmpB,0,openDark);
		PORTB = tmpB;
    }
}