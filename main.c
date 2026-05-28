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
#include <limits.h>
#include "constants.h"
#include "dsp.h"

#pragma config FNOSC = FRC // set Fast RC as oscillator, default is 7.27 MHz
#pragma config FWDTEN = OFF // give SF control over disabling watch

void uart_init(void);
void watchdog_disable(void);
bool watchdog_did_timeout(void);
void print_bin(uint32_t);

int main(void) {
    watchdog_disable();
    led_init();
    uart_init();
    uint32_t result = 0;
    
    printf("Q number 1: 0b");
    print_bin(q_num_1);
    printf("Q number 2: 0b");
    print_bin(q_num_2);

    printf("Q1 x Q2 = 0b");
    CORCON &= ~(1); // explicitely enable fractional multiply for dsp (should be default)
    asm(
        "clr A\n"
        "mov %0, w4\n"
        "mov %1, w5\n"
        "mac w4*w5, A\n"
        :
        :"r" (q_num_1), "r" (q_num_2)
        :"w4", "w5", "A"
    );
    print_bin(result);
    while(1) {
    }
}

void print_bin(uint32_t val)
{
    for (int i = 31; i >= 0; i--) {
        // Shift, mask with 1, and convert to char
        putchar(((val >> i) & 1) ? '1' : '0');
    }
    putchar('\n');
}