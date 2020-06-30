/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 12 May, 2020, 8:07 AM
 */

#include <xc.h>
#include"main.h"
#include"timers.h"
#include"digital_keypad.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#define PERIOD           100
unsigned char duty_cycle = 50;
unsigned char loop_count;
void software_pwm(unsigned char key)
{
    static unsigned int wait = 0;
    if(!wait--)
    {
        wait = 2500;           //for deley
    
    if(key == SW1)             //check the key is pressed or not
    {
            duty_cycle = 100;    //set the duty cycle max   
    }
    }
    if(loop_count == PERIOD)       //check the loop count is reached in period
    {
        loop_count = 0;
    }
    loop_count++;          //post increment the loop count
}
static void init_config(void) {
    LED_ARRAY = 0x00;
    LED_ARRAY_DDR = 0x00;
    LED1 = ON;
    init_digital_keypad();
    init_timer2();
    /*Peripheral interrupt enable bit (for Timer2)*/
    PEIE = 1;
    /*Enable all global interrupt*/
    GIE = 1;
}

void main(void) {
    unsigned char key;
    init_config();
    while (1) {
       
        key = read_digital_keypad(LEVEL);       //call the function for read the key

        software_pwm(key);              //call the function
        
    }
    return;
}
