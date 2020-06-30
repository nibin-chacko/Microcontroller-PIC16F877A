#include<xc.h>
#include"main.h"

void __interrupt() isr(void)
{
    static unsigned int count1 = 0,count2=0,count3=0;
    if(TMR0IF == 1)       //check the timer flag is enabled or not
    {
        /* TMR0 register value + 6 (offset count to get 250 Ticks) +2 instruction cycle*/
        TMR0 = TMR0 + 5 + 2;
        if(++count1 == 20000) //increment the count and check the condition
        {
            LED1 = !LED1;
            count1 = 0;
        }
       TMR0IF = 0;   
    }
     if(TMR1IF == 1)      //check the timer1 flag is enabled or not
    {
         
        if(++count2 == 20)  //increment the count2 and check the condition
        {
            LED2 = !LED2;
            count2 = 0;
        }
        TMR1IF = 0;
        
    }
    if(TMR2IF == 1)      //check the timer2 flag is enabled or not
    {
       if(++count3 == 5000) //increment the count3 value and check the condition
        {
            LED3 = !LED3;
            count3 = 0;
        }
       TMR2IF = 0;   
    }
    
}
