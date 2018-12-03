#include <xc.h>
#include "global.h"
#include "led.h"

void __attribute__((interrupt, no_auto_psv)) _INT0Interrupt(void)
{
    toggle_LedYellow();
    IFS0bits.INT0IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    RXread = U1RXREG;
    IFS0bits.U1RXIF = 0;
}