/*
 * File:   main.c
 * Author: marcr
 *
 * Created on 06 May 2026, 11:14
 */


#include "xc.h"
#include <string.h>

void uart_init(void);


int main(void) {

    uart_init();
    
    char msg[] = "Hello World!\r\n";
    
    while(1) {
        for(int i=0; i < strlen(msg); i++) {
            U1TXREG |= msg[i]; // write to tx buffer
            //while()
        }
        unsigned long i = 0xffffff;
        while(i--); // wait a little before sending again
        
    }
}

void uart_init(void) {
    // we want to use pins 21 (RB10) and 22 (RB11)
    // for UART
    // RB10 as Rx and RB11 as Tx
    // RP10 and RP11 are corresponding peripheral mux pin names
    
    // apparently once UART is enabled TRIS settings are overwritten anyways
    // so this should be redundant
    TRISB &= ~(1 << 10); // set RB11 as output by clearing the pin
    TRISB |= 1 << 15; // set RB10 (pin21) to input
    
    // bits 0 to 4 of RPINR18 register set where the input pin of UART1 receive is mapped
    // see DS70291G page 128
    RPINR18 |= 10; // set RP10 to UART1 input
    RPOR5 |= (0b00011 << 8); // set RP11 to UART1 output
    
    U1MODE |= 1 << 11; // disable flow control
    U1MODE |= 1 << 15; // set UARTEN (UART enable bit)
    U1STA |= 1 << 12; // Rx controlled by UART1
    U1STA |= 1 << 10; // enable Tx
    
    //TODO: configure baudrate
}