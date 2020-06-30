#include<xc.h>
#include "ssd.h"
#include"main.h"
void init_ssd(void)
{
    /*set the SSD data line as output*/
    SSD_DATA_PORT_DDR = 0x00;
    
    /*Setting the SSD control line as output(RA5 - RA2*/
    SSD_CONTROL_PORT_DDR =   SSD_CONTROL_PORT_DDR & 0xC3;
    
    /*Set the  control port*/
    SSD_CONTROL_PORT =     SSD_CONTROL_PORT & 0xC3;
   
}

void display(unsigned char data[])
{
    unsigned char digit;
    
    /*display the data in each arrays*/
    for(digit = 0;digit < MAX_SSD_CNT;digit++)
    {
        SSD_DATA_PORT =data[digit];     //assign the data
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit); //selecting the display  
        for(unsigned int i = 400;i--;);   //set the delay for vision
    }
}
