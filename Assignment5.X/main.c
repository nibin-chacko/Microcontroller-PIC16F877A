/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 30 May, 2020, 8:08 AM
 */
#include <xc.h>
#include"main.h"
#include"digital_keypad.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#define PERIOD         100      //define the maximum period as 100
void software_pwm(unsigned char key)
{
    static unsigned char duty_cycle = 50;     //set the initial state as 50%
    static unsigned char loop_count = 0;
    static unsigned int wait = 0;
    if(!wait--)                        //delay the function
    {
        wait = 500;
    if(key == SW1)                      //check the key1 read or not
    {
        if(duty_cycle != PERIOD)        //check the duty cycle  not equal to period then increment the duty cycle
        {
            duty_cycle++;
        }
        
    }
    if(key == SW2) //check the key2 read or not then
    {
        if(duty_cycle != 0) //check  the duty cycle not equal to 0 then
        {
            duty_cycle--; //duty cycle decrement
        }
    }
    }
    if(loop_count <= duty_cycle)        //to glow the led as 50% duty cycle
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    if(loop_count == 100)      //if loop count as 50 then assign loop count as 0 for again glow the led
    {
        loop_count = 0;
    }
    loop_count++;
}

static void init_config(void) {
    LED_ARRAY1 = 0x00;              //set the all leds are off
    LED_ARRAY1_DDR = 0x00;          //set the led as output
    init_digital_keypad();
            
}         
   void main(void)
   {
    unsigned char key;
    init_config();
    while (1) {
        key = read_digital_keypad(LEVEL);    //call the function to read the key
        software_pwm(key);        //call the function
        
        for(unsigned int i =100;i--; );
    }
      
    return;
}
