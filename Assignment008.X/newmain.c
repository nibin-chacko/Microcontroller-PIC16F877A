/*
 * File:   newmain.c
 * Author: Nibin chacko
 *
 * Created on 3 June, 2020, 9:59 PM
 */


#include <xc.h>

#include "main.h"
#include "adc.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

#define PERIOD           1024

void software_pwm(unsigned short adc_reg_val)
{
    unsigned short duty_cycle = adc_reg_val;
    static unsigned short loop_counter;
    static unsigned int wait = 0;
    unsigned short value;
    
    if (!wait--)
    {
        wait = 500;
        /* Condition to increase brightness */ 
        if (duty_cycle > value)  
        {
            value = duty_cycle;
            if(duty_cycle != PERIOD)
            {
            /* Increase brightness */
            duty_cycle++;
            }
        }
        /* Condition to decrease brightness */
        else if (duty_cycle < value)
        {
            value = duty_cycle;
            if(duty_cycle != 0)
            {
            /* Decrease brightness */
            duty_cycle--;
            }
        } 
    }
    
    /* To turn on led1 for the given duty cycle */
    if(loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    
    /* Condition to reset loop counter */
    if(loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    loop_counter++;

}

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_adc();
}

void main(void) {
    unsigned short adc_reg_val;
    init_config();

    while (1) {
     
        adc_reg_val = read_adc();

        software_pwm(adc_reg_val);
        
    }
    return;
}


