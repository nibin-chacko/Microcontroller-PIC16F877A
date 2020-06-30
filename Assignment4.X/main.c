/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 28 May, 2020, 11:55 AM
 */


#include <xc.h>
#include"main.h"
#include"timers.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    /*initilizing the timers*/
    init_timer0();
    init_timer1();
    init_timer2();
     /*Peripheral interrupt enable bit (for Timer2)*/
    PEIE = 1;
    /*Enable all global interrupt*/
    GIE = 1;
}

void main(void) {
    init_config();
    while (1) {
        ;
    }
    return;
}
