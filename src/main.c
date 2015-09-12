/*
 * main.c
 *
 * Created: 4/3/2014 8:36:43 AM
 *  Author: razius
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){
    // Clear Timer on Compare Match (CTC) Mode with OCRnA as top.
    TCCR4B |= _BV(WGM42);

    // Toggle OCnA on compare match
    TCCR4A |= _BV(COM4A0);

    // clk / (2 * prescaler * (1 + OCRnA))
    OCR4AH = 0x7A;
    OCR4AL = 0x12;

    // Setup Timer 0 pre-scaler to clk/256
    TCCR4B |= _BV(CS42);

    // Setup PH3 to output
    DDRH |= _BV(DDH3);

    // Enable MCU interrupt (set I-flag)
    sei();

    while (1) {
    }

    return 0;
}
