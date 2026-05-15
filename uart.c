/*
 * Initialises UART with 115200 baudrate assuming 7.37 Fast RC as clock source
 * Pins used are 21 Rx and 22 (Tx) on SPDIP
 */

#include "xc.h"

void MYUART_WriteChar(char c);

void uart_init(void) {
    // configure baudrate
    U1BRG = 1; // close enough to 115200
    
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
    
    unsigned int i = 0xffffff;
    while(i--); // wait a little
}


int write(int handle, void *buffer, unsigned int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        MYUART_WriteChar(*(char*) buffer++);
    }
    return (len);
}

void MYUART_WriteChar(char c) {
    if(c == '\n') MYUART_WriteChar('\r');
    U1TXREG = c; // write to tx buffer
    while(!(U1STA & 1<<8)); // wait until we are finished transmitting
}

