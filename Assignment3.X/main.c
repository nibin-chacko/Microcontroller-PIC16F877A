/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 15 May, 2020, 7:58 PM
 */


#include <xc.h>
#include"digital_keypad.h"
#include"main.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    LED_ARRAY1 = 0x00;            //Turn off the led initially
    LED_ARRAY1_DDR = 0x00;        //set the led as output
    init_digital_keypad();
}

void main(void) {
    unsigned short wait;
    unsigned char key;
    unsigned char key_copy;
    init_config();
    while (1) {
        key = read_digital_keypad(STATE);  //call the function for read the keypad
        if(key != ALL_RELEASED)            //if key is pressed the go inside
        {
           LED_ARRAY1 = 0x00;             //each key press first i turn off all leds
            key_copy = key;
        }
        if(!wait--)              //non blocking delay
        {
            wait = 3000;
            
            pattern(key_copy);   //call the function for blink the pattern
        }
        
    }
    return;
}
