#include<xc.h>
#include"ssd.h"

void init_ssd(void)
{
    /*Setting the ssd data lines as outputs*/
    SSD_DATA_PORT_DDR = 0X00;
    
    /*setting the ssd control lines as output RA5-RA2*/
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0XC3 ;
   
    SSD_CONTROL_PORT = SSD_CONTROL_PORT & 0XC3;
}

void display(unsigned char data[])
{
    unsigned char digit;
    for (digit = 0; digit< MAX_SSD_COUNT; digit++)
    {
     SSD_DATA_PORT = data[digit]; 
     SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0XC3) | (0X04 << digit);
    
     for (int wait = 400; wait--; );
    }
}