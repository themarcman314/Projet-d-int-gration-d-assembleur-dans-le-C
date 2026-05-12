/*
 * File:   main.c
 * Author: marcr
 *
 * Created on 06 May 2026, 11:14
 */


#include "xc.h"


int main(void) {
    // Microstick II red LED is on PORT A, PIN 0
    asm (
    "MOV 0x0, WREG\n"
    "MOV WREG, TRISA\n"
    "MOV #0, W2"
    );
    
    asm (
    "LOOP:\n"
    "MOV #0xffff, W1\n" // reset counter variable
    "LOOP_WAIT:\n"      // while counter is not over...
    "SUB #1, W1\n"        // substract 1 from reset counter
    "BRA NZ, LOOP_WAIT\n" // branch if result of previous operation is non 0
    "COM LATA, WREG\n"  // store complement of LATA in WREG
    "MOV WREG, LATA\n"  // toggle the LED
    "BRA LOOP"          // do it all again
    );
    
    return 0;
}
