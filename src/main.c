/*
 * main.c
 *
 * Created: 4/3/2014 8:36:43 AM
 *  Author: razius
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include <drivers/clock.h>

uint8_t CURRENT_DISPLAY_CASE = 0x00;
uint8_t BUTTON_PRESSED = 0;
uint8_t (*DISPLAY_FUNCTIONS[3])(void) = {
    clock_get_second,
    clock_get_minute,
    clock_get_hour
};


int main(void){
    clock_init(22, 49, 0);

    // Setup PORTH to output
    DDRH = 0xFF;

    // Enable external interrupt 7.
    EIMSK |= _BV(INT7);

    // Trigger external interrupt 0 on falling edge.
    EICRB |= _BV(ISC71);

    // Enable MCU interrupt (set I-flag)
    sei();

    while (1) {
        PORTH = ~(*DISPLAY_FUNCTIONS[CURRENT_DISPLAY_CASE])();
    }

    return 0;
}

ISR(INT7_vect){
    CURRENT_DISPLAY_CASE++;
    CURRENT_DISPLAY_CASE = CURRENT_DISPLAY_CASE % 3;
}
