/* 
 * File:   adc.h
 * Author: Nibin chacko
 *
 * Created on June 24, 2020, 9:19 AM
 */

#ifndef ADC_H
#define	ADC_H

#define CHANNEL0  0x00
#define CHANNEL1  0x01
#define CHANNEL2  0x02
#define CHANNEL3  0x03
#define CHANNEL4  0x04
#define CHANNEL5  0x05

unsigned short read_adc(unsigned char channel);
void init_adc(void);

#endif	/* ADC_H */

