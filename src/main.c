/*
 * main.c
 *
 * Created: 4/3/2014 8:36:43 AM
 *  Author: razius
 */

#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t SECONDS = 0x00;

int main(void){
    // Clear Timer on Compare Match (CTC) Mode with OCRnA as top.
    TCCR1B |= _BV(WGM12);

    // Enable Timer/Counter4 overflow interrupt.
    TIMSK1 = _BV(OCIE1A);

    // clk / (2 * prescaler * (1 + OCRnA))
    OCR1A = 0xF424;

    // Setup Timer 0 pre-scaler to clk/256
    TCCR1B |= _BV(CS12);

    // Setup PH3 to output
    DDRH = 0xFF;

    // Enable MCU interrupt (set I-flag)
    sei();

    while (1) {
        PORTH = ~SECONDS;
    }

    return 0;
}

ISR(TIMER1_COMPA_vect){
    // Setup PH3 to output
    // DDRH |= _BV(DDH3);
    // PORTH = PORTH << 1;
    if (SECONDS < 60) {
        SECONDS++;
    }
    else {
        SECONDS = 0x00;
    }
}
