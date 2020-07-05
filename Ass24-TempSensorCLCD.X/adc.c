#include<xc.h>



void init_adc(void)
{
   /*starting the adc module*/ 
   ADON = 1;   
   
   /* 1:8 clock*/
   ADCS1 = 0;
   ADCS0 = 1;
   
   /*selecting right justification*/
   ADFM = 1;
}

unsigned short read_adc(unsigned char channel)
{
    unsigned short adc_reg_val;
    
    // /*selecting the required channel*/
    ADCON0 = (ADCON0 & 0xC7) | (channel << 3);
    
    /*start the adc conversion*/
    GO = 1;
    
    /*wait for the conversion to complete*/
    while(nDONE);
    
    adc_reg_val = ((ADRESH<<8) | ADRESL);
    
    return adc_reg_val;
}