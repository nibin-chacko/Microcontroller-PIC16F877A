/* 
 * File:   main.h
 * Author: Nibin
 *
 * Created on 19 June, 2020, 8:08 AM
 */

#ifndef MAINJ_H
#define	MAINJ_H

#define LED8       RB7
#define LED8_DDR   TRISB7

#define OFF         0
#define ON          1

extern char *password,user[10];
extern int blink,i,chance;
extern unsigned char loop_count,duty_cycle;

#endif	/* MAINJ_H */

