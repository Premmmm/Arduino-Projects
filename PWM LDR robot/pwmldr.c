#include<avr/io.h>
#include<util/delay.h>

/*void init_adc()
{
ADCSRA|=0b00000001<<ADEN;
ADCSRA|=0b00000001<<ADPS2;
ADMUX|=0b00000001<<REFS0;
}

unsigned int read_adc(int p)
{
ADMUX&=0b01000000;
ADMUX|=p;
ADCSRA|=0b00000001<<ADSC;
while((ADCSRA&(0b00000001<<ADIF))==0)
{}
ADCSRA|=0b00000001<<ADIF;
return(ADC);
}*/

void main()
{
DDRB=0b11111111;
while(1)
{
PORTB=0b00001010;
_delay_ms(50);
PORTB=0b00000000;
_delay_ms(50);
}
}
	
