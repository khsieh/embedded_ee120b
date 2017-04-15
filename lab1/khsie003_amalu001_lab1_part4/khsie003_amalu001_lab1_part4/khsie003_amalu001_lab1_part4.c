/*
 * khsie003_amalu001_lab1_part4.c
 *
 * Created: 1/11/2015 6:31:18 PM
 *  Author: student
 */ 


#include <avr/io.h>


//x is the word to access, k-th bit to get
unsigned char GetBit(unsigned char x, unsigned char k){
	return((x&(0x01<<k))!=0);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    unsigned char ones = 0x00;
	while(1)
    {
		ones = 0x00;
		
        for(int i = 0; i < 8; ++i)
		{
			ones += GetBit(PORTA, i);
			ones += GetBit(PORTB, i);
			
		}
		PORTC = ones;
    }
}