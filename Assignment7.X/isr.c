#include<xc.h>
#include"main.h"
void __interrupt() isr(void)
{
    static unsigned int count = 0;
    if(TMR2IF == 1)         //check the timer2 flag is enabled or not
    {
        if(++count == 6250)         //check the count as 6250
        {
            duty_cycle = 50;           //decrement the duty cycle as half
            count = 0;
        }
        else
        {
           if(loop_count <= duty_cycle)       //check the loopcount is lessthan or equal with duty cycle
           {
               LED1 = ON;
           }
           else  
           {
               LED1 = OFF;
           }
        }
           TMR2IF = 0;
    }
    if(TMR2IF == 1)      //check the flag
    {
        LED1 = OFF;
        TMR2IF = 0;
    }
}
