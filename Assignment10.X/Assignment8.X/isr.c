#include<xc.h>
#include"main.h"
#include"ssd.h"
void __interrupt() isr(void)
{
    static unsigned long int count = 0;
    if(TMR2IF == 1)                                         //check the flag is enabled or not
    {
       if(++count == 1200000)                             //to increment the minute value after every 60sec
        {
            min++;
            count = 0;
        }
       if(decimal++ == 20000)                          //to blink the decimal point every 1sec
       {   
           SSD_DATA_PORT = 0x80;                     //set the RD7 as 1
           SSD_CONTROL_PORT = 0x08;                 //set the RA3 as 1
           for(unsigned long int i = 3200;i--; );  //provide delay for vision
           decimal = 0;  
       }

       TMR2IF = 0;                                //clear the interrupt flag
    }
}
