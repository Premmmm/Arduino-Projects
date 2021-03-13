#include<avr/io.h>
#include<util/delay.h>
void init_adc()
{
ADCSRA|=0b00000001<<ADEN;
ADCSRA|=0b00000001<<ADPS2;
ADMUX|=0b00000001<<REFS0;
}

unsigned int read_adc(int p)
{
ADMUX&=0b01000000;
ADMUX=ADMUX|p;
ADCSRA=ADCSRA|(0b00000001<<ADSC);
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);
}



void main()                                         
{ 
DDRD=0b00000000;    // to set part d as input
DDRB=0b11111111;  // to set part b as output
PORTD=0b11111111; // to pull up input
init_adc();
_delay_ms(200);
unsigned int b;
unsigned int p;
unsigned int z;
unsigned int T;
unsigned int TON1;
unsigned int TOFF1;
int f;

while(1)  //infinite loop
{
f=PIND;
if(f==0b11111000)         // obstacle present 
{  
PORTB=0b00010000;	  // buzzer       
}
else
{
p=read_adc(0);
if(p<=1000)    // LDR  and line follower
{
f=PIND;
if(f==0b11111111)  //black black; 
PORTB=0b00011010;   // BUZZ AND MOVE FORWARD

if(f==0b11111110)	//black white ;
PORTB=0b00000110;   // LEFT

if(f==0b11111101)	//white black; 
PORTB=0b00001001;   // RIGHT

if(f==0b11111100)   //white white; 
PORTB=0b00001010;   // FROWARD

}
else if(p>1000)           // Potentiometer 
{
z=read_adc(1);
b=(z/40);
T=25.6;
TOFF1=b;
TON1=T-TOFF1;
f=PIND;
if(f==0b11111111)   //black black; 
{
PORTB=0b00011010;   // BUZZ AND MOVE FORWARD
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
if(f==0b11111110)	//black white ;
{
PORTB=0b00000110;   // LEFT
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
if(f==0b11111101)	//white black; 
{
PORTB=0b00001001;   // RIGHT
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
if(f==0b11111100)   //white white; 
{
PORTB=0b00001010;   // FROWARD
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
}
}
}
}
