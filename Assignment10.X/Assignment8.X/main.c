/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 05 Jun, 2020, 8:07 AM
 */
#include <xc.h>
#include"ssd.h"
#include"timers.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
unsigned int count = 0;
unsigned int min = 0;
unsigned int decimal= 0;

static void init_config(void) {
    /*initialize the timer2 */
    init_timer2();
    /*initialize the SSD*/
    init_ssd();
    
    /*Enable the peripheral interrupt*/
    PEIE = 1;
    /*Enable the Global interrupt*/
    GIE = 1;
    
}

void main(void) {
    init_config();
    unsigned int hr = 12;             //set the initial value of hour as 12
    unsigned char digit[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    unsigned char ssd[MAX_SSD_CNT];
    unsigned int prev_minute = 1;
    while (1) {
        
        if(prev_minute != min)               //if the minute is not increment it doesn't disturb the SSD
        {
                ssd[1] = digit[(hr/1)%10];   //extracting the hour values
                ssd[0] = digit[(hr/10)%10];
                ssd[3] = digit[(min/1)%10];   //extracting the minute values
                ssd[2] = digit[(min/10)%10];
            
                if(min == 59)                     //check the minute reach 59     
                {
                    hr++;                         //then increment the hour value
                    min = 0;
                    if(hr == 24)                  //if the hour value is reach 24 then set as 1
                    {
                        hr = 1;
                    }
                }

          prev_minute = min;                  //assign the previous minute as new minute
        }
        /* call the function for display*/
     display(ssd);

    }
    
    return;
}
