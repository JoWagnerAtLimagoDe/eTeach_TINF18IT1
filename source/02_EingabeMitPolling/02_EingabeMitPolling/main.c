/*
 * 02_EingabeMitPolling.c
 *
 * Created: 13.04.2020 15:58:10
 * Author : JoachimWagner
 */ 

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLEAR_BIT(PORT,BIT) PORT&=~(1<<BIT)


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void init() {
	
	// PB5 als Ausgang
	DDRB |= 0b00100000;
	
	// D2 und D3 als Eingang
	//CLEAR_BIT(DDRD, DDD2);
	//CLEAR_BIT(DDRD, DDD3);
	DDRD = 0;
	
	// Pullup für D2 und D3
	//SET_BIT(PORTD, PORTD2);
	//SET_BIT(PORTD, PORTD3);
	PORTD = 255;
	
	// BuildIn LED Off
	PORTB |= 1 << PINB5 ;
	
}

int main() {
	init();
	while(1) {
		if ( ! (PIND & (1 << PIND2))) 
			PORTB = 0xFF;
			
		if ( ! (PIND & (1 << PIND3)))
			PORTB = 0x00;
	}
}


