/*
 * File:   main.c
 * Author: marcr
 *
 * Created on 06 May 2026, 11:14
 */


#include "xc.h"

#define LED_LATCH _LATA0
#define LED_TRIS _TRISA0

int main(void) {
    // Microstick II red LED is on PORT A, PIN 0
    LED_TRIS = 0; // set as output
    while(1) {
        int i = 100000;
        while(i--); // wait a while
        LED_LATCH = !LED_LATCH; // toggle the LED
    }
    return 0;
}
