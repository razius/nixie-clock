/*
 * clock.c
 *
 * Created: 16/09/2015 20:43:56
 *  Author: razius
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include <drivers/clock.h>

static uint8_t clock_second = 0;
static uint8_t clock_minute = 0;
static uint8_t clock_hour = 0;

void clock_init(uint8_t hour, uint8_t minute, uint8_t second){
    // Clear Timer on Compare Match (CTC) Mode with OCRnA as top.
    TCCR1B |= _BV(WGM12);

    // Enable Timer/Counter1 compare match interrupt.
    TIMSK1 = _BV(OCIE1A);

    // clk / (2 * prescaler * (1 + OCRnA))
    OCR1A = 0xF424;

    // Setup Timer 0 pre-scaler to clk/256
    TCCR1B |= _BV(CS12);

    clock_hour = hour % 24;
    clock_minute = minute % 60;
    clock_second = second % 60;
}

uint8_t clock_get_second(void){
    return clock_second;
}

uint8_t clock_get_minute(void){
    return clock_minute;
}

uint8_t clock_get_hour(void){
    return clock_hour;
}

ISR(TIMER1_COMPA_vect){
    clock_second++;
    clock_second = clock_second % 60;
}
