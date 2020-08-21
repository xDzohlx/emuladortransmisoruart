/*
* puertoserie.cpp
*
* Created: 01/10/2014 12:32:31 p.m.
* Author: Dzohl
*/


#include
#include

volatile static uint8_t cont = 0x00;
volatile static uint8_t dato = 0x55;
volatile static uint8_t dato1 = dato;

ISR(TIM0_COMPA_vect){
if (cont == 0x01)
{
PORTA &= ~(1<
}
if ((cont > 0x01)&&(cont < 0x0A))
{
PORTA = dato & 0x01;
dato = (dato>>1);
}

if (cont >= 0x0A)
{
PORTA |= (1< if (cont >= 0x12)
{
dato = dato1;
cont = 0x00;
}
}
cont ++;
}

int main(void){
TCCR0A |= (1< TIMSK0 |= (1< TCCR0B |= (1< OCR0A = 0x68;
DDRA |= (1< TCNT0 = 0x00;
PORTA = 0x01;
sei();
while(1){

}//while
}//maim
