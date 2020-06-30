/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 2 June, 2020, 8:39 AM
 */
#include <xc.h>
#include"ssd.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
unsigned int count = 0;
unsigned int i = 0;
unsigned int j = 1;
unsigned int k = 2;
unsigned int l = 3;
static void init_config(void) {
   /*initialize the SSD*/
    init_ssd();
}

void main(void) {
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[12]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,EMPTY,EMPTY};
    unsigned int prev_count = 1;
    unsigned int wait= 0;
    init_config();
    
    while (1) {
        
        if(prev_count != count)  //check the previous count
        {
        ssd[0] = digit[i];
        ssd[1] = digit[j];
        ssd[2] = digit[k];
        ssd[3] = digit[l];
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
