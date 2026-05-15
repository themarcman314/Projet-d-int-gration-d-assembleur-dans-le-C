#include <xc.h>

#define LED_LATCH _LATA0
#define LED_TRIS _TRISA0

void led_init(void) {
    LED_TRIS = 0;
}

void led_on(void) {
    LED_LATCH = 1;
}

void led_off(void) {
    LED_LATCH = 0;
}

void led_toggle(void) {
    LED_LATCH = !LED_LATCH;
}