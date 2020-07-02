#include<xc.h>
#include"main.h"
void __interrupt() isr(void)
{
    static unsigned short value;
    static unsigned int wait = 0;
    if(TMR2IF == 1)       //check the interrupt flag enabled or not
    {
        if(!wait--)
        {
            wait = 500;
        
            duty_cycle = adc_reg_val;
            /* Condition to increase brightness */ 
            if (duty_cycle > value)  
            {
                value = duty_cycle;
                if(duty_cycle != PERIOD)
                {
                /* Increase brightness */
                duty_cycle += 10;
                }
            }
            /* Condition to decrease brightness */
            else if (duty_cycle < value)
            {
                value = duty_cycle;
                if(duty_cycle != 0)
                {
                /* Decrease brightness */
                duty_cycle-=10;
                }
            }
        }
        if(loop_counter <= duty_cycle)//check the loop_count less tha duty_cycle then on the led else off
        {
            LED1 = ON;
        }
        else
        {
            LED1 = OFF;
        }
        if(loop_counter == PERIOD)
        {
            loop_counter = 0;
        }
        loop_counter++;
       TMR2IF = 0;   
    }
}
