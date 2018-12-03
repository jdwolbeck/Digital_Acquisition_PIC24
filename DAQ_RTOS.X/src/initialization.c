#include <xc.h>
#include "initialization.h"

void App_init(void)
{
    Gpio_init();
}

void Gpio_init(void)
{
    LATB = 0;
    // TRIS registers
    TRISBbits.TRISB15 = 0;  //LED
    TRISBbits.TRISB14 = 0;  //LED
    TRISBbits.TRISB13 = 0;  //LED
    TRISBbits.TRISB4 = 0;   //UART TX
    //ANS registers
    ANSB = 0;
}
