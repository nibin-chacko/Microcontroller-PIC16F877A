#include<xc.h>

void init_timer0(void)
{
     TMR0 = 6;
     /*Setting the internal clock*/
    
    T0CS = 0;
    
    /*The timer interrupt is enabled*/
    
    TMR0IE = 1;
    
   
    /*Assigning the prescale to watch dog*/
    
    PSA = 1; //if there PSA is assigned to one so led blink in one second if PSA is not assign the led will blink in two second
}
void init_timer1(void)
{
    /*Enable the timer1*/
    TMR1ON = 1;
    
    /*Enable the prescale bit 1:8*/
    T1CKPS1 = 1;
    T1CKPS0 = 0;
 
    
    
    /*1000*(4MHZ)/(4*8)=62500        65535-62500=3035 converted to hexadecimal 0x0BDB so assign msb as 0x0B and lsb as 0xDC*/
    TMR1H = 0x0B;
    TMR1L = 0xDC;
    
       
    /*Enable the timer1 bit*/
    TMR1IE = 1;
    
    
}

void init_timer2(void)
{
    
    /*selecting scale as 1:4*/
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    
    /*The timer interrupt is enabled*/
    
    TMR2IE = 1;
    
  
   
    /*Loading the preload register as 250*/
    PR2 = 250;
    /*Switching on timer 2*/
    TMR2ON = 1;
}