#include<xc.h>
#include "matrix_keypad.h"

void init_matrix_keypad(void)
{
    /*setting columns as inputs (RB0-RB2)*/
    MATRIX_KEYPAD_COLUMN_PORT_DDR = MATRIX_KEYPAD_COLUMN_PORT_DDR | 0X07;
    
     /*setting rows as outputs (RD0-RD3)*/
    MATRIX_KEYPAD_ROW_PORT_DDR = MATRIX_KEYPAD_ROW_PORT_DDR & 0XF0;
    
    /*Enabling PORTB pullups*/
    nRBPU = 0;
    
    /*making all rows high to start with*/
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;
}   

static unsigned char scan_keypad(void)
{
    int i;
    ROW1 = LOW;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;
    
    for (i=100;i--;);
    
    if (COL1 == LOW)
    {
        return 1;
    }
     if (COL2 == LOW)
    {
        return 2;
    }
     if (COL3 == LOW)
    {
        return 3;
    }
    
    ROW1 = HI;
    ROW2 = LOW;
    ROW3 = HI;
    ROW4 = HI;
    for (i=100;i--;);
    if (COL1 == LOW)
    {
        return 4;
    }
     if (COL2 == LOW)
    {
        return 5;
    }
     if (COL3 == LOW)
    {
        return 6;
    }
    
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = LOW;
    ROW4 = HI;
    for (i=100;i--;);
    if (COL1 == LOW)
    {
        return 7;
    }
     if (COL2 == LOW)
    {
        return 8;
    }
     if (COL3 == LOW)
    {
        return 9;
    }
    
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = LOW;
    for (i=100;i--;);
    if (COL1 == LOW)
    {
        return '*';
    }
     if (COL2 == LOW)
    {
        return 0;
    }
     if (COL3 == LOW)
    {
        return '#';
    }
    
    return ALL_RELEASED;
}

unsigned char read_matrix_keypad(unsigned char mode)
{
    static unsigned char once = 1;
    unsigned char key;
    
    key = scan_keypad();
    
    if (mode == LEVEL)
    {
       return key; 
    }
    
    else
    {
        if ((key != ALL_RELEASED) && once)
        {
          once = 0; 
          return key;
        }
        else if (key == ALL_RELEASED)
        {
            once = 1;
        }
    }
    return ALL_RELEASED;
}