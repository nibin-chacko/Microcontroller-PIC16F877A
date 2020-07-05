/*
 * File:   main.c
 * Author: Nibin Chacko
 *
 * Created on June 3, 2020, 3:38 PM
 */


#include <xc.h>
#include "adc.h"
#include "clcd.h"
#include "main.h"


#pragma config WDTE = OFF      // Watchdog Timer ~Enable bit (WDT ~enabled)




void display(unsigned short adc_reg_val)
{
  float temperature, voltage;
 
  
    /* 4.88 mv is obtained from adc resolution (FSR/2^10)*/
    /* voltage is the output voltage at the sensor*/
    /* vout is converted to temperature in celcius (divide by 10mv)*/
  
  voltage = (float) adc_reg_val * 0.00488;
  temperature = voltage /0.01;
  
  char buff[4];
  int i;
  clcd_print("Temp:",LINE2(6));
  
  /* convert int to string*/
  i=2;
  do
  {
      buff[i] = ((int)temperature % 10) + '0';
      temperature = (int)temperature / 10;
  } 
  while(i--);
  buff[3]='\0';
  
  /* print the temperature in 'C'*/
  clcd_print(buff,LINE2(11));
  clcd_print("C",LINE2(15));
   
}

static void init_config(void) {
    
    init_clcd();
    init_adc();
    
    clcd_print("LM35 TEMPER TEST",LINE1(0));
    
    
}

void main(void) {
    unsigned short adc_reg_val;
    init_config();
    char d=0xdf;
    clcd_putch(d,LINE2(14));

    while (1) 
    {
      adc_reg_val= read_adc(CHANNEL0); //read the reg val in AN0
      display(adc_reg_val);
    }
    return;
}
