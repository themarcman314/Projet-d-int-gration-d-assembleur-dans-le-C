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
    "MOV 0x0, WREG\n"
    "MOV WREG, TRISA"
    );
    
    while(1) {
        long int i = 0xffff; 
        while(i--);
        asm (
        "COM LATA, WREG\n"
        "MOV WREG, LATA"
        );
        //LATA = !LATA;
    }
    return 0;
}
