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
    TRISA = 0;
    while(1) {
        long long int i = 100000;
        while(i--);
        LATA = !LATA ;

    }
    return 0;
}
