/*
 * Blink.c
 *
 * Created: 05.02.2018 18:54:38
 * Author : Joachim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT) PORT |= (1 << BIT)
#define CLEAR_BIT(PORT,BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT ^=(1<<BIT) 

int main(void)
{
	// Data Direction Register -> B
    //DDRB=  1 << DDB5; // Gesetztes Bit = Ausgang
    DDRB |= 0b100000;
	PORTB |= 1 << PORTB5;
	
	//PORTB= 1 << PORTB5;
    while (1)
    {
	    SET_BIT(PORTB,PORTB5);
	    _delay_ms(1000);
	    CLEAR_BIT(PORTB,PORTB5);
	    _delay_ms(100);
		
		//TOGGLE_BIT(PORTB,PORTB5);
		//_delay_ms(500);
	    
    }
}

