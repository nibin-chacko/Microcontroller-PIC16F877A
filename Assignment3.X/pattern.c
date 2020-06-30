#include<xc.h>
#include"main.h"
#include"digital_keypad.h"
void pattern(unsigned char key)
{
    static unsigned char flag = 1,i;
    static unsigned input = 0x55;
    static unsigned input1 = 0xF0;
    
    if(key == SW1)            //check the key is switch 1
    {
        if(flag == 1)         //this for glow the led right to left
        {
            LED_ARRAY1 = LED_ARRAY1 | (1<<i); //glowing the leds one by one
        }
        if(flag == 2)   //this for turn of the led right to left
        {
            LED_ARRAY1 = LED_ARRAY1 << 1; //turn of the led one by one
        }
        if(flag == 3)  //this for glowing the led left to right
        {
            LED_ARRAY1 |= 0x80 >> i;  //glowing the led one by one
        }
        if(flag == 4)        //turn off the led left to right
        {
            LED_ARRAY1 = LED_ARRAY1 >> 1;  //turn of the led one by one
        }
        i++;             //increment the i value
        if(i == 8)       //check the all leds are glowed
        {
            
            i = 0;
            flag++;
            if(flag > 4)
            {
                flag = 1;
            }
        }
    }
    else if(key == SW2)             //check the switch is 2
    {
        if(flag == 1)
        {
        LED_ARRAY1 |=0x80 >> i;          //this for led glowing right to left
        }
        if(flag == 2)
        {
            LED_ARRAY1 = LED_ARRAY1>>1;      //turn of the led right to left one by one
        }
        i++;
        if(i == 8)
        {
            i = 0;
            flag++;
            if(flag > 2)
            {
                flag = 1;
            }
        }
       
    }   
    else if(key == SW3)            //check the switch 3
    {
        input = ~input;             //take inverse of input
        LED_ARRAY1 = input;
    }
    else if(key == SW4)
    {
        input1 = ~input1;      //take the inverse of input1
        LED_ARRAY1 = input1;
    }
}
