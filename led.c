#include <xc.h>
#include <stdint.h>

#define LED_LATCH _LATA0
#define LED_TRIS _TRISA0

void led_init(void) {
    //LED_TRIS = 0;
    *((volatile unsigned *)0x02c0U) &= ~1U;
}

void led_on(void) {
    //LED_LATCH = 1;
    *((volatile uint16_t *)0x02C4U) |= 1U;
}

void led_off(void) {
    //LED_LATCH = 0;
    *((volatile uint16_t *)0x02C4U) &= ~1U;

}

void led_toggle(void) {
    LED_LATCH = !LED_LATCH;
}