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


unsigned char loop_count = 0;
unsigned char key;
unsigned int cur_duty = 50;
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
    unsigned int wait = 0;
    init_config();
    while (1) {

        key = read_digital_keypad(LEVEL);       //call the function for read the key
       
        if(loop_count <= cur_duty)    //check the loop_count and duty cycle
        {
            LED1 = ON;
        }
        else
        {
            LED1 = OFF;
        }
        if(!wait--)                        //for provide delay
        { 
            wait = 2000;
            if(key == SW1)                 //check the which key selected
            {
                if(cur_duty != PERIOD)       //for increasing brightness
                {
                    cur_duty++;

                }
            }
            else if(key == SW2)          //check the which key is pressed
            {
                if(cur_duty != 0)          //for decreasing the brightness
                {
                    cur_duty--;

                }
            }   
        }
    }
    return;
}
