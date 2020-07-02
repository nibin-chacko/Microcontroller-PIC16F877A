/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 2 July, 2020, 8:23 AM
 */


#include <xc.h>
#include "adc.h"
#include "main.h"
#include "timers.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
/*initialize the variables*/
unsigned short adc_reg_val=0;
unsigned short duty_cycle = 0;
unsigned int loop_counter = 0;

static void init_config(void) {
     LED_ARRAY1 = 0x00;
     LED_ARRAY1_DDR = 0x00;
    
     init_timer2();
     init_adc();
     /*interrupt enable*/
     PEIE = 1;
     GIE  = 1;
}

void main(void) {
    init_config();
    while (1) {
        adc_reg_val = read_adc();
        
    }
        
    return;
}
