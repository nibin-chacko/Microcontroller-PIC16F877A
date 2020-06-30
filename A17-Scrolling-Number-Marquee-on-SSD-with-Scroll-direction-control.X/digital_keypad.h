/* 
 * File:   digital_keypad.h
 * Author: Nibin chacko
 *
 * Created on 27 April, 2020, 10:10 PM
 */

#ifndef DIGITAL_KEYPAD_H
#define	DIGITAL_KEYPAD_H

#define LEVEL_DETECTION        0
#define LEVEL                  0

#define STATE                  1
#define STATE_DETECTION        1

#define KEYPAD_PORT_DDR        TRISB
#define KEYPAD_PORT            PORTB





#define INPUT_LINES            0x3F


#define ALL_RELEASED           INPUT_LINES

#define SW1                    0x3E
#define SW2                    0x3D
#define SW3                    0x3B
#define SW4                    0x37
#define SW5                    0x2F
#define SW6                    0x1F

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char mode);
#endif	/* DIGITAL_KEYPAD_H */

