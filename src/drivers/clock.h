/*
 * clock.h
 *
 * Created: 16/09/2015 20:43:56
 *  Author: razius
 */

#ifndef CLOCK_H_
#define CLOCK_H_

void clock_init(uint8_t hour, uint8_t minute, uint8_t second);
uint8_t clock_get_second(void);
uint8_t clock_get_minute(void);
uint8_t clock_get_hour(void);

#endif /* CLOCK_H_ */
