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
#include "vendor_dsp/include/dsp.h"

#pragma config FNOSC = FRC // set Fast RC as oscillator, default is 7.27 MHz
#pragma config FWDTEN = OFF // give SF control over disabling watch

int results[400] = {0};

void uart_init(void);
void watchdog_disable(void);
bool watchdog_did_timeout(void);
void print_bin(uint32_t const val, unsigned const num_bits);

int main(void) {
    watchdog_disable();
    led_init();
    uart_init();
    
        //uint16_t *result_p_upper = (uint16_t *)&result + 1;
    
    
//    printf("Q number 1: 0b");
//    print_bin(q_num_1, sizeof(q_num_1)* 8);
//    printf("Q number 2: 0b");
//    print_bin(q_num_2, sizeof(q_num_1)* 8);
//
//    printf("Q1 x Q2 = 0b");
    
    CORCON &= ~(1); // explicitely enable fractional multiply for dsp (should be default)
    
    // IIR low pass filter
    // y[n] = alpha * x[n] + (1 - alpha) * y[n - 1]
    // result is 0 initialized
    // therefore we can jump straight into MAC loop
    // for first order IIR we cannot benefit from MAC prefetching, since x[n] is a constant and we have to wait for y[n-1] to finish computing 
    asm(
        "clr A\n"
        "mov %0, w1\n"
        "mov %1, w4\n"
        "mov %2, w5\n"
        "mov %3, w6\n"
        "mov #0, w7\n"
        "mpy w4* w5, A\n" // alpha * x[n]
        "sac A, w5\n"
    
        "do %4, loop_end\n"
        "mac w6* w7, A\n"
        "sac A, w7\n" // store result for next itteration
        "clr A\n"
    /*
     * It's important to note that there is in fact a loss of precision here
     * we are truncating the lower 16 bits of our result.
     * a product of two q15 numbers does in fact give us a q31 result.
     * here we are choosing to ignore the lower bits and accept the loss in precision
     */
        "mov w7, [w1++]\n" // store upper word of A
        "mov w5, ACCAH\n" // prepare for next mac
        "loop_end:"

        : 
        : "r" (results+1), "r" (alpha_q), "r" (step_q), "r" (alpha_complement), "r" (sizeof(results)/sizeof(int)-2)
        :"w4", "w5", "w6", "w7", "w1"
    );

    printf("\n\n\n\n");
    for (int i = 0; i < sizeof(results)/sizeof(int); i++) printf("%d,%f\n", i, Fract2Float(results[i]));
    
    while(1) {
    }
}

void print_bin(uint32_t const val, unsigned const num_bits)
{
    for (int i = num_bits; i >= 0; i--) {
        // Shift, mask with 1, and convert to char
        putchar(((val >> i) & 1) ? '1' : '0');
    }
    putchar('\n');
}