/* 
 * File:   main.h
 * Author: Nibin chacko
 *
 * Created on 12 May, 2020, 8:25 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#define LED1                  RD0

#define LED_ARRAY             PORTD
#define LED_ARRAY_DDR         TRISD

#define ON                    1
#define OFF                   0

extern unsigned char duty_cycle;
extern unsigned char loop_count;

#endif	/* MAIN_H */

