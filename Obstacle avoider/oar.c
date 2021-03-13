#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRD=0b00000000;    // to set part d as input
DDRB=0b11111111;  // to set part b as output
PORTD=0b11111111; // to pull up input

int c;

while(1)  //infinite loop
{
c=PIND;
if(c==0b11111111)  //no obstacle
     PORTB=0b00001010; //forward
if(c==0b11111110)          // right obstacle
     PORTB=0b00000110;	    //left
if(c==0b11111101)        //center obstacle
{
 PORTB=0b00000101;       //back and right
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(200);
}
if(c==0b11111100)      // obstacle to center and right
{
PORTB=0b00000101;       // back and left
_delay_ms(200);
PORTB=0b00000110;
_delay_ms(200);
}
if(c==0b11111011)      // obstacle to left
PORTB=0b00001001;         // right

if(c==0b11111010)        // obstacle to both right and left
{
PORTB=0b00000101;       // back and right
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(200);
}
if(c==0b11111001)      // obstacle to center and left
{
PORTB=0b00000101;   // back and right
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(200);
}

if(c==0b11111000)   // obstacle up front 
{
PORTB=0b00000101;   //  back and u-turn
_delay_ms(200);
PORTB=0b00001001;
_delay_ms(1000);
}
}	
}