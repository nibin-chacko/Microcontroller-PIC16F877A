/* 
 * File:   main.h
 * Author: Nibin chacko
 *
 * Created on 3 June, 2020, 9:57 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#define LED1            RD0

#define LED_ARRAY1      PORTD
#define LED_ARRAY1_DDR  TRISD

#define ON              1
#define OFF             0

#define PERIOD          1024
extern unsigned short duty_cycle,adc_reg_val;
extern unsigned int loop_counter;
#endif	/* MAIN_H */

