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
#include <stdbool.h>


#pragma config FNOSC = FRC // set Fast RC as oscillator, default is 7.27 MHz
#pragma config FWDTEN = OFF // give SF control over disabling watchdog

void uart_init(void);
void watchdog_disable(void);
bool watchdog_did_timeout(void);


int main(void) {
    watchdog_disable();
    led_init();
    
    uart_init();
    unsigned long count = 0;
    while(1) {
        printf("Hello World %lu\n", count++, RCON);
        unsigned long i = 0xffffU;
        while(i--); // wait a little before sending again
    }
}