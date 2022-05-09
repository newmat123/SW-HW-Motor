/*
 * Motor.c
 *
 * Created: 5/3/2022 8:52:21 AM
 *  Author: Algorithm (Oliver G.)
 */ 
#include <avr/io.h>
#include <stdbool.h>

bool reverseDirection = false;

void initMotor(){
	
	TCCR1A = 0b10100011;
	TCCR1B = 0b00000001;
	
	OCR1A = 0;
}

void setSpeed(unsigned char speed){
	if (!reverseDirection)
	{
		OCR1B = 0;
		OCR1A = speed * 4;
	} 
	else {
		OCR1A = 0;
		OCR1B = speed * 4;
	}
}
	
void switchDirection(){
	reverseDirection = !reverseDirection
}

void testMotor(){
	DDRA = 0;
	DDRB = 0xFF;

	PORTB = 0;

	while(1){

		if (~PINA & (1 << 0)){
			setSpeed(0); //0%
		}
		if (~PINA & (1 << 1))
		{
			setSpeed(64); //25%
		}
		if (~PINA & (1 << 2))
		{
			setSpeed(128); //50%
		}
		if (~PINA & (1 << 3))
		{
			setSpeed(192); //75%
		}
		if (~PINA & (1 << 4))
		{
			setSpeed(255); //100%
		}
		
		if (~PINA & (1 << 7))
		{
			reverseDirection = true;
		}
		else{
			reverseDirection = false;
		}
	}
}