/**
 * khsie003_amalu001_lab2_part2.c
 * Kevin Hsieh, khsie003@ucr.edu
 * Alyza Malunao, amalu001@ucr.edu
 * Section 23
 * (From an earlier lab) Buttons are connected to PA0 and PA1. The output for
 * PORTB is initially 0. Pressing PA0 increments PORTB (stopping at 9). Pressing
 * PA1 decrements PORTB (stopping at 0). If both buttons are depressed (even if
 * not initially simultaneously), PORTB resets to 0. If a reset occurs, both buttons
 * should be fully released before additional increments or decrements are allowed
 * to happen. Use LEDs (and resistors) on PORTB. Use a state machine (not
 * synchronous) captured in C.
 * Author: student
 * I acknowledge all content contained herein, excluding template or example code,
 * is my own original work.
 */ 

#include <avr/io.h>
// #include "RIMS.h"

enum States {init, waitPress, press, waitRelease} State;

//x is the word to be modified, k-th bit to modify, b is the new bit
unsigned char SetBit(unsigned char x, unsigned char k, unsigned b){
	return(b?x|(0x01<<k):x&!(0x01<<k));
}

//x is the word to access, k-th bit to get
unsigned char GetBit(unsigned char x, unsigned char k){
	return((x&(0x01<<k))!=0);
}

// unsigned char counter = 0x00;
// unsigned char PC = 0;
unsigned char flag = 0;
unsigned char counter = 0;

void Tick(){
	unsigned char PC = PINC;
	unsigned char LED = PORTA;

	switch(State){ //transitions
		case init:
			State = waitPress;
			break;
		case waitPress:
			if(!GetBit(PC,0)){
				State = press;
			}
			else{
				State = waitPress;
			}
			break;
		case press:
			State = waitRelease;
			break;
		case waitRelease:
			if(!GetBit(PC,0)){
				State = waitRelease;
			}
			else{
				State = waitPress;
			}
			break;
		default:
			State = init;
			break;
	} // Transitions

	switch(State){ //State Actions
		case init:
			break;
		case waitPress:
			break;
		case press:
			if(LED == 0x00 || LED == 0x3F){
				flag = !flag;
			}
			if(flag){
				LED = SetBit(LED,counter,1);
				counter = (counter < 5) ? counter + 1 : counter;
			}
			else{
				LED = SetBit(LED,counter,0);
				counter = (counter > 0) ? counter - 1 : counter;
			}
			break;
		case waitRelease:
			break;
		default:
			break;
	} //State Actions
	PORTA = LED;
}

int main(void)
{
	DDRA = 0xFF; PORTA = 0x00; //output
	DDRC = 0x00; PORTC = 0xFF; //input

	State = init;
    while(1){
        Tick();
    }
    return 0;
}