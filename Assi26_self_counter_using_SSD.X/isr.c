#include<xc.h>
#include"main.h"
void __interrupt() isr(void)
{
    static unsigned int wait = 0;
    if(TMR2IF == 1)  //check the interrupt flag enabled or not
    {
        if(!wait--)        //its for provide delay
        {
            wait = 10000;
            if(count1 != 10000)  //if the value not reach maximum then only increment
            {
                count1++;    
            }
            else   //else set it as zero
            {
                 count1 = 0;
            }
        }
      
       TMR2IF = 0; 
    }
}
