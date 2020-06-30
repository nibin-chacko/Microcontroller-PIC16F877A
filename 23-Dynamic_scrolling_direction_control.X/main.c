/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 29 June, 2020, 9:13 PM
 */


#include <xc.h>
#include <string.h>
#include "clcd.h"
#include "matrix_keypad.h"
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#define LEFT                     0
#define RIGHT                    1

int pos = 4;
char start = 0,edit = 1,direction = 1,right = 1,left = 0;
static void init_config(void) {
    init_clcd();
    init_matrix_keypad();
    
}

void main(void) {
    init_config();
    unsigned char key,i = 0,digit_place = 0,temp1;
    unsigned int wait,wait1 = 1000;
    char str[2]={0xFF,'0'};
    char message[17]="                 ";
    message[16]='\0';
    char copy_str[17];
    
    /*print the following in CLCD*/
    clcd_print("ENTER NEW NUMBER", LINE1(0));
    clcd_print("Msg:", LINE2(0));
    while(1)
    {
        if(edit == 1 && (start == 0))
        {
            if(!wait--)
            {
                wait = 500;
                /*to blink the cursor and number in edit mode*/
                clcd_putch(str[i],LINE2(pos)); 
                i++;
                if(i > 1)
                {
                    i = 0;
                }
            }
        }
        key = read_matrix_keypad(STATE);
        /*this for increment the value for press the key*/
        if(key == 1 && edit)
        {
            str[1]++;
            if(str[1] > '9')
            {
                str[1] = '0';
            }
            /*assign that value to message array*/
            message[digit_place] = str[1];
        }
        /*to change the direction to left*/
        if ((key == 1) && (edit == 0))
        {
            direction = LEFT;
               
        }
        /*to change the direction to right*/
        if ((key == 2) && (edit == 0))
        {
            direction = RIGHT;
               
        }
        /*to decrement*/
         if ((key == 2) && edit )
        {
            str[1]--;
            
                    if (str[1] < '0')
                    {
                        str[1] = '9';
                    }
            /*assign the str to message*/
            message[digit_place]=str[1];
               
        }
        /*to accept the key*/
        if ((key == 5) && edit)
        {
            clcd_print("            ",LINE2(4));
            clcd_print(message,LINE2(4));
            str[1]='0';
           pos++;
           if (pos>15)
           {
               pos=4;
           }
           /*increment the digit place in message array*/
           digit_place++;
        }
        /*to strat and stop*/
        if (key == 3)
        {
            strcpy(copy_str, message);       
             start = !start; //assign start as 1
            clcd_print("                ",LINE2(0));
            edit = 0;
        }
        /*to edit*/
        if (key == 4)
        {
            pos = 4;
            edit = 1;
            start = 0;
            clcd_print("ENTER NEW NUMBER", LINE1(0));
            clcd_print("Msg:            ", LINE2(0));
            
        }
        /*to delete char*/
        if (key == 6 && edit)
        {
            /*assign the deleted position as blank*/
            message[digit_place]= ' ';
            digit_place--;
            if (pos-- == 4)
            {
                pos = 15;
            }
            clcd_print(message,LINE2(4));
        }
        else
        {
            
            
           if (start == 1)
           {
               
               if (wait1-- <= 0)
            {
                wait1 = 1000;
                
                if(direction == RIGHT)
                {
                
                    /*save the first character in a variable*/
                    temp1= copy_str[0];
           
                      /*transfer each character to before place*/
                    for (int i=0; i<=15; i++)
                    {   
                        copy_str[i]= copy_str[i+1];
                    }
        
                    /*store the fisrt character into last place*/
                    copy_str[15]=temp1;
        
               }
                if(direction == LEFT)
                {
                
                    /*save the first character in a variable*/
                    temp1=copy_str[15];
           
                      /*transfer each character to before place*/
                    for (int i=15; i>=0; i--)
                    {   
                       copy_str[i]= copy_str[i-1];
                    }
        
                    /*store the fisrt character into last place*/
                    copy_str[0]=temp1;
        
               }
                
                clcd_print(copy_str, LINE2(0));
            }
            
            }
        }	
    }
    return;
}
