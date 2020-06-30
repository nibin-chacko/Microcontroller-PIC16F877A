/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 20 June, 2020, 5:29 PM
 */


#include <xc.h>
#include"main.h"
#include "clcd.h"
#include"Matrix_keypad.h"
#include"timers.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

unsigned char pos = 0;
unsigned char duty_cycle = 0;

void software_pwm(unsigned char key)
{
    char block = 0xFF;
    char clear = 0x01;
    
    static unsigned int wait = 0;
    if(!wait--)
    {
        wait = 1000;
        
        if(key == 1)   //check the key 1 is pressed or not
        {
            if(duty_cycle != PERIOD)  //check the duty cycle reach 100 or not,if it not reach 100 then increment the duty cycle
            {
                duty_cycle = duty_cycle + 6; //duty cycle increment with 6, 100/16=6.25-we want 100 duty cycle maximum ,16 characters in 1 line of clcd,dividing the period with blocks
                clcd_putch(block,LINE2(pos++)); //call the function for printing blocks
            }
        }
        else if(key == 2)   //check the key 1 is pressed or not
        {
            if(duty_cycle != 0)  //check the duty cycle not reach minimum ,then decrease the duty cycle
            {
                duty_cycle = duty_cycle - 6;  //duty cycle decrement with 6, 100/16=6.25-we want 100 duty cycle maximum ,16 characters in 1 line of clcd,dividing the period with blocks
                clcd_putch(clear,LINE2(pos--)); //call the function for clear the screen
            }
            if(duty_cycle == 0)   //if the duty cycle reach zero the clear the block in first position
            {
                clcd_putch(clear,LINE2(0));
            }
        }
        
    }
}
static void init_config(void) {
    LED1_DDR = 0;  //set it is an output device
    LED1 = OFF;      //turn off the led
    
    /*initialization of clcd and matrix keypad*/
    init_clcd();
    init_matrix_keypad();
    init_timer2();
    /*interrupt enabling*/
    PEIE  = 1;  
    GIE = 1;
    /*call the function to print the string in first line of clcd*/
    clcd_print("LED Dimmer Level",LINE1(0));
}

void main(void) {
    
    init_config();  //call the functions
    unsigned char key;
    
    while (1) {
        
        key = read_matrix_keypad(LEVEL); //read which key is pressed    
        software_pwm(key);
    }
    return;
}
