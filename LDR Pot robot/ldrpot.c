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
DDRB=0b11111111;
init_adc();
_delay_ms(200);
unsigned int b;
unsigned int p;
unsigned int z;
unsigned int T;
unsigned int TON1;
unsigned int TOFF1;

while(1) 
{ 
p=read_adc(0);
if(p<=842)    // LDR
{
PORTB=0b000001010;
}
else if(p>842)           // Potentiometer 
{
z=read_adc(1);
b=(z/40);
T=25.6;
TOFF1=b;
TON1=T-TOFF1;
PORTB=0b00001010;
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
}
}	
