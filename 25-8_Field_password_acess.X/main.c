/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 19 June, 2020, 8:04 AM
 */


#include <xc.h>
#include<string.h>
#include "main.h"
#include "clcd.h"
#include "Matrix_keypad.h"
#include "timers.h"
#define PERIOD     100
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

char *password="12121212";
char user[10]="";
char initial = 1;
int cursor = 0,i = 3,chance=5,blink = 0;
unsigned char loop_count,duty_cycle = 0;
unsigned char count = 0;
void ledblink(int chance) /* To blink led when chances to enter password decreases  */
{   
    static unsigned int wait = 0;
    if (!wait--)
    {
        wait = 20 * (chance); /* To increase the speed of blinking led */

        LED8 = ~LED8;
    }
}
static void init_config(void) {
    init_clcd();
    init_timer2();
    init_matrix_keypad();
    LED8_DDR = 0;
    LED8 = OFF;
    GIE = 1;
    PEIE = 1;
}

void main(void) {
    unsigned int wait = 0,j = 0;
    unsigned char key;
    init_config();
    
    while (1) {
        
       if (chance < 5 && chance >= 0) /* To blink led */
        {
            ledblink(chance);
        }
       
        key = read_matrix_keypad(STATE);
        
        if(initial)     //initial conditions
        {
            if(chance == 0)   //if user enterd wrong password 5 times
            {
                clcd_print("Chances Exausted",LINE1(0));
                clcd_print("Reset the board ",LINE2(0));
                i = 17;
                initial = 0;
            }
            else
            {
                clcd_print(" Enter Password ",LINE1(0));
                clcd_print("                ",LINE2(0));
                user[9]=0;
                initial = 0,j = 0,i = 3,wait = 0;
            }
        }
        
       if(key != ALL_RELEASED)  //if the key pressed 
        {
            if(i <= 10)     //printing position
            {
                user[j]='0' + key;            //store the user enter data
                clcd_putch('*',LINE2(i));
                j++;
                i++;
            }
        }
        
        else if(j == 8)   //check the user enter 7 data then we need to add null
        {
            user[j]='\0';
           
           if(strcmp(user,password) == 0)    //check the orginal password and user enterd password
           {
               clcd_print(" Excellent  You ",LINE1(0));
               clcd_print("Cracked the code",LINE2(0));
               wait = 4;                  //break the entering mode
               chance = 5;
           }
           else if(chance != 0)  //if the chance is zero then block the entering interface
           {
               initial = 1;
               chance--;       //decrement the chances  
           }
           
        }
        if(!wait--)    //indicating the enter mode
        {
            wait = 1;
            clcd_putch('_',LINE2(i));
        }
        else
        {
            clcd_putch(' ',LINE2(i));
        }
      
    }
        
    return;
}
