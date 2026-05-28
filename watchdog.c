#include <xc.h>
#include <stdbool.h>

void watchdog_disable(void) {
    RCONbits.SWDTEN = 0;
}

bool watchdog_did_timeout(void) {
    return (RCON & 1U << 4U) >> 4U;
}