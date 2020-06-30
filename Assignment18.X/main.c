/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 11 June, 2020, 8:43 AM
 */


#include <xc.h>
#include<string.h>
#include"clcd.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
static void init_config(void) {
    
    init_clcd();
    
}

void main(void) {
    init_config();
    int wait = 10000;
    /*initial printing*/
    char data[]="0000000000";
    char data1[]="9999999999";
    clcd_print("10 Digit counter",LINE1(0));
    clcd_print("count:",LINE2(0));
    clcd_print(data,LINE2(6));
    while (1) {
        
        for(int i = 9 ;i >= 0;i--)   //loop for check the each array value
        {
            if(data[i] >'9')   //if the value reach 9 then assign to 0 and increment the previous value
            {
                data[i-1]++;
                data[i] = '0';
            }
        }
            clcd_print(data,LINE2(6));   //call the function for update the screen
            if(strcmp(data,"9999999999")==0) //check the string reach maximum then stop
            {
                exit();
            }
        
        data[9]++;     //increment the last value

    }
    return;
}
