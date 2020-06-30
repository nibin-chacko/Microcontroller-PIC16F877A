#include <xc.h>

void init_adc(void)
{
    /* Selecting Right Justification */
    ADFM = 1;
    
    /* Starting the ADC Module */
    ADON = 1;
}

unsigned short read_adc(void)
{
    unsigned short adc_reg_val;
    
    /* Start the ADC conversion */
    GO = 1;
    /* Wait for the convertion to complete */
    while (nDONE);
    
    adc_reg_val = (ADRESH << 8) | ADRESL;
    
    return adc_reg_val;
}
