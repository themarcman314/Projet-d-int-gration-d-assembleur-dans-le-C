/*
 * File:   main.c
 * Author: marcr
 *
 * Created on 06 May 2026, 11:14
 */


#include "xc.h"


int main(void) {
    // Microstick II red LED is on PORT A, PIN 0
    //TRISA = 0;
//    LATA = 1;
    asm (
    "MOV 0x0, W0\n"
    "MOV W0, TRISA"
    );
    
    while(1) {
        long int i = 0xffff; 
        while(i--);
        LATA = !LATA;
    }
    return 0;
}
