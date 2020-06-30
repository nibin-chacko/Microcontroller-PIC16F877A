/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 10 Jun, 2020, 1:41 PM
 */

#include <xc.h>
#include "clcd.h"
#include <string.h>
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_clcd();
}

void main(void) {
    init_config();
    char data[]="Scrolling Demo  ";
    char c;
    int len = strlen(data);
    int i;
    while (1) {
        
        c = data[len - 1];       //take the last char of the string
        for(i = len - 1;i > 0;i--)  //shift the data to right side
        {
            data[i] = data[i - 1];
        }
        data[0] = c;         //put the data first of the string
        data[16] = 0;        //assign the last of the array as 0
        clcd_print(data,LINE1(0)); //call the function for print the string
        for(unsigned long int wait = 100000;wait--;);  //provide delay
        }
    return;
}
