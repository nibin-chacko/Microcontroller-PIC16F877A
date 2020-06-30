#include<xc.h>


void init_timer2(void)
{
    
    /*selecting scale as 1:16*/
    T2CKPS0 = 1;
    T2CKPS1 = 1;
    
    /*The timer interrupt is enabled*/
    
    TMR2IE = 1;
    
  
   
    /*Loading the preload register as 250*/
    PR2 = 250;
    /*Switching on timer 2*/
    TMR2ON = 1;
}
