/*
 * File:   main.c
 * Author: marcr
 *
 * Created on 06 May 2026, 11:14
 */


#include "xc.h"
#include "led.h"
#include <string.h>
#include <stdio.h>


#pragma FOSCSEL_FNOSC = FRC // set Fast RC as oscillator, default is 7.27 MHz


void uart_init(void);


int main(void) {
    led_init();
    
    // TODO: fix watchdog reset from occuring
    if(RCON & 1<<4) led_on();

    uart_init();
    //char msg[20] = "";
    unsigned long count = 0;
    while(1) {
        printf("Hello World %lu\n", count++);
        unsigned long i = 0xffff;
        while(i--); // wait a little before sending again
    }
}