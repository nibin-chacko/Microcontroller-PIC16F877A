#include<xc.h>
#include"digital_keypad.h"


void init_digital_keypad(void)
{
    /*set keypad port as input*/
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES; 
}

unsigned char read_digital_keypad(unsigned char mode)     //unsigned is used for it is a 8bit register
{
    static unsigned char once = 1;        //this is a function repeatly called and if you dont mentioned static the space is in stack and any thing go to static is auto we want to store in data segment
    if(mode == LEVEL)
    {
        return KEYPAD_PORT & INPUT_LINES;
    }
    else
    {
        if(((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;
            
            return KEYPAD_PORT & INPUT_LINES;
        }
        else if(((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED))
        {
            once = 1;
        }
    
    }
    
    return ALL_RELEASED;
}