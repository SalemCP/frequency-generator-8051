#include "timer0.h"
#include "quad_7segment.h"

sbit control1 = P0^3;            // Defining LED pin
sbit control2 = P0^2;            // Defining LED pin
sbit control3 = P0^1;            // Defining LED pin
sbit control4 = P0^0;            // Defining LED pin
#define DIGIT_0 0xC0
#define DIGIT_1 0xF9
#define DIGIT_2 0xA4
#define DIGIT_3 0xB0
#define DIGIT_4 0x99
#define DIGIT_5 0x92
#define DIGIT_6 0x82
#define DIGIT_7 0xF8
#define DIGIT_8 0x80
#define DIGIT_9 0x90
#define BLANK 0xFF

void init_7segment(){
	init_timer0();
	control1=0; //turn off control
	control2=0; //turn off control
	control3=0; //turn off control
	control4=0; //turn off control
	P2=DIGIT_4; //clear PORT
}
unsigned char numToPattern(unsigned char digit){
	unsigned char pattern=0;
	switch (digit) {
    case 0:
						pattern=DIGIT_0;
            break;
    case 1:
						pattern=DIGIT_1;
            break;
    case 2:
						pattern=DIGIT_2;
            break;
    case 3:
						pattern=DIGIT_3;
        break;
    case 4:
						pattern=DIGIT_4;
        break;
    case 5:
						pattern=DIGIT_5;
        break;
    case 6:
						pattern=DIGIT_6;
        break;
    case 7:
						pattern=DIGIT_7;
        break;
    case 8:
						pattern=DIGIT_8;
        break;
    case 9:
						pattern=DIGIT_9;
        break;
    default:
        // Display a blank segment
						pattern=BLANK;
        break;
}
	return pattern;
}



void show_7segment(unsigned int num){
	unsigned char digit1=num%10;
	unsigned char digit2=(num/10)%10;
	unsigned char digit3=(num/100)%10;
	unsigned char digit4=(num/1000)%10;
	unsigned char pattern1=numToPattern(digit1);
	unsigned char pattern2=numToPattern(digit2);
	unsigned char pattern3=numToPattern(digit3);
	unsigned char pattern4=numToPattern(digit4);
	delay_timer0();
	control1 = 1;           
	control2 = 0;           
	control3 = 0;            
	control4 = 0;
	P2=	pattern1;
	delay_timer0();
	
	control1 = 0;           
	control2 = 1;           
	control3 = 0;            
	control4 = 0;
	P2=	pattern2;
	delay_timer0();
	
	control1 = 0;           
	control2 = 0;           
	control3 = 1;            
	control4 = 0;
	P2=	pattern3;
	delay_timer0();
	
	control1 = 0;           
	control2 = 0;           
	control3 = 0;            
	control4 = 1;
	P2=	pattern4;
	delay_timer0();
	

}
