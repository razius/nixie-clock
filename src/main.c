/*
 * main.c
 *
 * Created: 4/3/2014 8:36:43 AM
 *  Author: razius
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
    // Set PH0 to output and turn all leds on.
    DDRH = 0xFF;
    PORTH = 0x00;

    // Enable MCU interrupt (set I-flag)
    sei();

    while (1) {
    }

    return 0;
}
