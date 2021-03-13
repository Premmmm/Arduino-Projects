#include<avr/io.h>
#include<util/delay.h>
void init_adc()
{
ADCSRA=ADCSRA|(0b00000001<<ADEN);
ADCSRA=ADCSRA|(0b00000001<<ADPS2);
ADMUX=ADMUX|(0b00000001<<REFS0);
}
unsigned int read_adc(int Z)
{
ADMUX&=0b01000000;
ADMUX=ADMUX|Z;
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
unsigned int a;
unsigned int b;
unsigned int p;
unsigned int q;
unsigned int T;
unsigned int TON1;
unsigned int TON2;
unsigned int TOFF1;
unsigned int TOFF2;
while(1)
{
p=read_adc(0);
a=(p/40);
T=25.6;
TOFF1=a;
TON1=T-TOFF1;
q=read_adc(1);
b=(q/40);
T=25.6;
TOFF2=b;
TON2=T-TOFF2;
if(p<752 && q<752)
{
PORTB=0b00001010;
_delay_ms(TON2);
PORTB=0b00000000;
_delay_ms(TOFF2);
}
else if(p<752)
{
PORTB=0b00000110;
_delay_ms(TON1);
PORTB=0b00000000;
_delay_ms(TOFF1);
}
else if(q<752)
{
PORTB=0b00001001;
_delay_ms(TON2);
PORTB=0b00000000;
_delay_ms(TOFF2);
}
}
}