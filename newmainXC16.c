#include <p33FJ128MC802.h>
#include <xc.h>

#define LED  	 _LATA0
#define LED_TRIS _TRISA0

int main(void) {
    _T1IF = 0;
    _T1IE = 0;
    //TMR1 = 000;
    PR1 = 0x3000;
    T1CONbits.TCKPS = 3;    //presclaire
    T1CONbits.TON = 1;      //Lancement du tmr1

    LED_TRIS = 0;
    
    enum
    {
        IDLE, BLINK_LED // Add other states here...
    } demoState;
    
    while (1) 
    {
        switch (demoState)
        {
            case IDLE:
                if (_T1IF == 1) 
                {
                    _T1IF = 0;
                    demoState = BLINK_LED;
                    T1CONbits.TON = 0;      //Arrêt du tmr1
                    TMR1 = 0x0000;
                    T1CONbits.TON = 1;      //Lancement du tmr1
                }
                // Add other idle tasks here...
                break;

            case BLINK_LED:
                LED ^= 1; // Toggle the LED
                demoState = IDLE;

                
                break;

            // Add other case states here...
            default:
                demoState = IDLE;
                break;
        }
    }
    return 0;
}
