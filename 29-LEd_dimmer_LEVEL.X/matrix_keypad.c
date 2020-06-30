#include <xc.h>
#include "Matrix_keypad.h"

void init_matrix_keypad(void)
{
    /* Setting the Columns as Inputs (RB2 - RB0)*/
    MATRIX_KEYPAD_COLUMN_PORT_DDR = MATRIX_KEYPAD_COLUMN_PORT_DDR | 0x07;
    /* Setting the Rows as Output (RD3 - RD0)*/
    MATRIX_KEYPAD_ROW_PORT_DDR = 1;
    
    /* Enabling PORTB Pullups */
    nRBPU = 0;
    
    /* Making all the Rows HIGH to start with */
   
    ROW3 = HI;
}

static unsigned char scan_keypad(void)
{
    int i;
    
   
    ROW3 = HI;   
    
    for (i = 100; i--; );
    
    if (COL1 == LOW)
    {
        return 1;
    }
    else if (COL2 == LOW)
    {
        return 2;
    }
    else if (COL3 == LOW)
    {
        return 3;
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
