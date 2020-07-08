/*
 * File:   main.c
 * Author: Nibin chacko
 *
 * Created on 5 July, 2020, 9:21 PM
 */

#include <xc.h>
#include"digital_keypad.h"
#include"ssd.h"


#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
unsigned int count1 = 0;

static void init_config(void) {
    /*initialisation the digital keypad,ssd and timer */
    init_digital_keypad();
    init_ssd();
    /*Enable the interrupts*/
}

void main(void) {
    unsigned char key,prev_count = 1,long_press = 0,check = 0;
    unsigned int count1 = 0;
    unsigned char digit[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    unsigned char ssd[MAX_SSD_CNT];
    unsigned int wait = 0,start = 0;
    init_config();
    while (1) {
        /*call the function to read the key from user press*/
        
        
        key = read_digital_keypad(LEVEL);
        
       if(key == SW1)
        {
            if(!wait--)
            {
                wait = 100;
                count1++;
            }
        }
        if(key == SW2)
        {
            /*check the user is pressed key2 long time set the count as zero*/
            if(long_press++ == 200)
            {
                long_press = 0;
                count1 = 0;
            }
            eeprom_write(0x00, (count1 | 0x00)); //in our eeprom only one byte can be store at a time,so if the count greater than 255 we cant store,so take the 1byte of lsb and store it into eeprom address 0x00 and msb byte stored in eeprom adress 0x01 
            eeprom_write(0x01, (count1 >> 8) | 0x00);
            /*indication of data is stored*/
            eeprom_write(0x02, 1);
        }
        /*check the epprom value of adress 0x01 is 1 then check start == 0,its for restart,read the stored data to count1*/
        else if((check = eeprom_read(0x02)) && check == 1 && start ==  0)
        {
            count1 = ((eeprom_read(0x01) << 8) |count1) |(eeprom_read(0x00));
            check = 0;
            start = 1;
        }
           if(count1 != prev_count)
            {
               /*Assign the count values in ssd*/
                ssd[0] = digit[(count1/1000) % 10];
                ssd[1] = digit[(count1/100) % 10];
                ssd[2] = digit[(count1/10) % 10];
                ssd[3] = digit[(count1/1) % 10];
                prev_count = count1;
            }
        
        display(ssd);
    }
    return;
}
