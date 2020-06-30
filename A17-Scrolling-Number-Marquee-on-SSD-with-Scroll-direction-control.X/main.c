/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 2 June, 2020, 8:39 AM
 */
#include <xc.h>
#include"ssd.h"
#include"digital_keypad.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
unsigned int count = 0;
 int i = 9;
 int j = 8;
 int k = 7;
 int l = 6;
int LEFT = 1,RIGHT=0,STOP = 0,START = 1;
static void init_config(void) {
   /*initialize the SSD*/
    init_ssd();
    /*initialize the switches*/
    init_digital_keypad();
}

void main(void) {
    int count1 = 0;
    unsigned char key;
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[12]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,EMPTY,EMPTY};
    unsigned int prev_count = 1;
    unsigned int wait= 0;
    init_config();
    
    while (1) {
        key = read_digital_keypad(STATE);     //call the function for read the switch
       if(key == SW1)              //check the switch for left scrolling 
        {
            LEFT  = 1;
            RIGHT = 0;
            STOP  = 0;
            START = 0;
            count1=0;
        }
        else if(key == SW2)                   //switch for right scrolling
        {
            LEFT  = 0;
            RIGHT = 1;
            STOP  = 0;
            START = 0;
            count1= 0;
        }

        else if(key == SW3)           //check the switch for stop and start
        {
            count1++;
            STOP  = 1;
            START = 0;
            if(count1 == 2)              //check the user press s3 2 times
            {
                if(LEFT == 1)
                {
                  START = 0;
                  STOP = 0;
                }
                else if(RIGHT == 1)
                {
                    START = 2;
                    STOP = 0;
                }
            count1 = 0;
            }
        }
        if(prev_count != count)  //check the previous count
        {
        ssd[3] = digit[i];
        ssd[2] = digit[j];
        ssd[1] = digit[k];
        ssd[0] = digit[l];
        prev_count = count;
        }

        display(ssd);  //call the function for display
        if(count == 10)
        {
            count = 0;
        }
      
    }
    return;
}
