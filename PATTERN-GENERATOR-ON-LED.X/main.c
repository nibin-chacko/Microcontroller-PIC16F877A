/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 24 April, 2020, 6:12 AM
 */


#include <xc.h>
#include"main.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)


static void init_config(void) {
    LED_ARRAY1 = 0xFF;              //set Led as high
    LED_ARRAY1_DDR = 0x00;          //TRISD macro
}

void main(void) {
    unsigned int i;
    unsigned int mask;
    unsigned int y;
    unsigned int j;
    unsigned int k;
    init_config();          //call the function
    
    while (1) {
        
        y = 0xFF;
        k = 8;
        for(j=0;j<=8;j++)   //loop for increasing D0 to D7
        {
            mask = 0xFF;
            mask = mask>>k;            //Right shift for blinking
            LED_ARRAY1 = y & mask;     //AND with mask for blinking
        
        for(i=50000;i--; ); 
         k--;                         //Reduce the k value
        }
        k = 0;
        
        for(j = 0;j <= 8;j++)       //loop for decreasing    D7 to D0
        {
            mask = 0xFF;
            mask = mask << k;        //left shift for blinking
            LED_ARRAY1 = y & mask;
            for(i=50000;i--;);
            k++;
        }
        k = 8;
        
        for(j = 0;j <= 8;j++)    //loop for increasing    D0 to D7
        {
            mask = 0xFF;
            mask = mask << k;             //left shift for blinking
            LED_ARRAY1 = y & mask;
            for(i=50000;i--;);
            k--;
        }
         k = 0;
        for(j=0;j<=8;j++)       //llop for decreasing D7 to D0
        {
            mask = 0xFF;
            mask = mask>>k;            //Right shift for blinking
            LED_ARRAY1 = y & mask;     //AND with mask
        
        for(i=50000;i--; ); 
         k++;                         //Reduce the k value
        }
        
    }
    return;
}
