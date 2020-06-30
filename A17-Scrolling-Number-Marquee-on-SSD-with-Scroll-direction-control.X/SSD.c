#include<xc.h>
#include "ssd.h"
#include"main.h"
void init_ssd(void)
{
    /*set the SSD data line as output*/
    SSD_DATA_PORT_DDR = 0x00;
    
    /*Setting the SSD control line as output(RA5 - RA2*/
    SSD_CONTROL_PORT_DDR =   SSD_CONTROL_PORT_DDR & 0xC3;
    
    
    SSD_CONTROL_PORT =     SSD_CONTROL_PORT & 0xC3;
   
}

void display(unsigned char data[])
{
    unsigned char digit;
    static unsigned int wait= 0;
       if(wait == 500)     //provide delay
        {
           wait = 0;
        if((LEFT == 1 && STOP == 0)|| START == 1)
        {
           i--;            //Decrement the each array value
           j--;
           k--;
           l--;
              if(i < 0)     //if array value is reached first then set array value start from last
               {
                   i = 12;
               }
               if(j < 0)    //if array value is reached first then set array value start from last
               {
                   j = 12;
               }
               if(k < 0)    //if array value is reached first then set array value start from last
               {
                   k = 12;
               }
               if(l < 0)   //if array value is reached first then set array value start from last
               {
                   l = 12;
               } 
           }
           else if((RIGHT == 1 & STOP == 0) || START == 2)
           {

               i++;                       //increment the arrays
               j++;
               k++;
               l++;

               if(i > 12)     //if array value is reached last then set array value start from first
               {
                   i = 0;
               }
               if(j > 12)    //if array value is reached last then set array value start from first
               {
                   j = 0;
               }
               if(k > 12)    //if array value is reached last then set array value start from first
               {
                   k = 0;
               }
               if(l > 12)   //if array value is reached last then set array value start from first
               {
                   l = 0;
               }
            }
         
          count++;      //increment the count for delay
        }
         wait++;
         
         if(LEFT == 1 || STOP == 1 || START == 1)   //left scrolling
         {              
            for(digit = 0;digit < 4;digit++)    //loop for display the values in 4 SSD
            {
                SSD_DATA_PORT =data[digit];     //assign the values
                SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x20 >> digit);  //for enable the each SSD  
                for(unsigned int i = 400;i--;);                //for power of vision
            }
         }
         else if(RIGHT == 1 || STOP == 1 || START == 0)   //right scrolling
         {              
            for(digit = 0;digit < 4;digit++)    //loop for display the values in 4 SSD
            {
                SSD_DATA_PORT =data[digit];     //assign the values
                SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x20 >> digit);  //for enable the each SSD  
                for(unsigned int i = 400;i--;);                //for power of vision

            }
         }         
}
