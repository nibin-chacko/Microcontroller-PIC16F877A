#include<xc.h>
#include"main.h"
void __interrupt() isr(void)
{  
    static unsigned int count = 0;
    if(TMR2IF == 1)           //check the interrupt flag is enabled or not
    { 
        if(++count <= duty_cycle)  //if the count less than duty cycle then led on
          {
            LED1 = ON;     
          }
        else
        {
            LED1 = OFF;
        }
        if(count == PERIOD)  //if the count equal to period then set the count as 0 
        {
            count = 0;
        }
         
        TMR2IF = 0;            //turn of the interrupt flag
    }
}