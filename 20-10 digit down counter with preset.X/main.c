/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 22 June, 2020, 8:58 AM
 */


#include <xc.h>
#include<string.h>
#include "Matrix_keypad.h"
#include "clcd.h"


#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_clcd();
    init_matrix_keypad();
}

void main(void) {
    unsigned char key,wait= 0,i = 15,j,start = 0,count = 0;
    char array[17]={'C','o','u','n','t',':','0','0','0','0','0','0','0','0','0','0','\0'};
    char data1[]="0000000000";
    init_config();
    clcd_print("10 Digit counter",LINE1(0));
    clcd_print("Count:",LINE2(0));
    
    while (1) {
        clcd_print(array,LINE2(0));
        key = read_matrix_keypad(STATE);  ///call the function the scan the key
       
        if(key == 1)    //if key 1 is pressed then increment the value of the current cursor position
        {
            array[i]++;
            if(array[i] > '9')
            {
                array[i] = '0';
            }    
        }
        
        if(key == 2)  //if key is 2 the change the cursor position
        {
            i--;
            if(i < 6)  //this for if the cursor reach max position set the cursor position last
            {
                i = 15;
            }
        }
        if(key == 3)  //if key 3 is pressed then start to down count
        {
            start = 1;
        }
        if(start == 1)
        {
            j = 6;            //digit starting position
            while(array[j] != '0')   //check the wastage zeros
            {
                j++;
                count++;       //counting zeros
            }
            while((strcmp(array,"Count:0000000000")) != 0)   //check the down count reach minimum
            {
                for(int k = (j+count);k <= 15;k++)   //arrange the datas in array
                {
                    if(array[k] < '0')   //if the value reach 0 then assign to 9 and decrement the previous value
                    {
                        array[k-1]--;
                        array[k] = '9';
                    }

                    
                }
                clcd_print(array,LINE2(0));   //call the function for update the screen
                array[15]--;          //decrement the last value
            }
            start = 0;
            i = 15;
            count = 0;
        }
        if(start == 0)
        {
            if(!wait--)   //delay for blink the cursor
            {
              wait = 6;
              clcd_putch(255,LINE2(i));

            }
        }
    }
    return;
}
