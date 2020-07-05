/*
 * File:   main.c
 * Author: NIBIN CHACKO
 *
 * Created on June 3, 2020, 3:38 PM
 */


#include <xc.h>
#include "adc.h"
#include "ssd.h"
#include "main.h"


#pragma config WDTE = OFF      // Watchdog Timer ~Enable bit (WDT ~enabled)




static void init_config(void) {
 
    init_ssd();
    
    init_adc();
   
}

void main(void) {
    unsigned char digits[11]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,C};
    unsigned char ssd[MAX_SSD_COUNT];
    unsigned short adc_reg_val;
    float temperature;
    float voltage;
    ssd[3] = digits[10];  //celcius unit in ssd3
    
    init_config();

    while (1)
    {
        adc_reg_val = read_adc(CHANNEL0);  //read the reg val in AN0
       
        /* 4.88 mv is obtained from adc resolution (FSR/2^10)*/
        /* voltage is the output voltage at the sensor*/
        /* vout is converted to temperature in celcius (divide by 10mv)*/
        
        voltage = (float) adc_reg_val * 0.00488;
        temperature = voltage /0.01;
        
        ssd[2] = digits[((int)temperature/1) % 10];
        ssd[1] = digits[((int)temperature/10) % 10];
        ssd[0] = digits[((int)temperature/100) % 10];
        display(ssd);
    }
    return;
}
