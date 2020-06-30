#include<xc.h>
#include"main.h"
#include"digital_keypad.h"
void __interrupt() isr(void)
{
  
    if(TMR2IF == 1)           //check the interrupt flag is enabled or not
    {       
        if(loop_count == 100)  //check the loop_count attain max duty_cycle
        {
            loop_count = 0;
        }
        loop_count++;          //increment the loop count
        TMR2IF = 0;            //turn of the interrupt flag
    }
}   
