#include <xc.h>
#include <stdbool.h>

void Int0_init(void)
{
    IFS0bits.INT0IF = 0;        //Reset INT0 interrupt flag
    INTCON1bits.NSTDIS = 0;     //Disable interrupt nesting
    IPC0bits.INT0IP = 4;        //Set high priority.
    INTCON2bits.INT0EP = 0;     //Set Interrupt 0's polarity to rising
    IEC0bits.INT0IE = 1;        //Enable Interrupt 0
}

void toggle_LedRed(void)
{
    LATBbits.LATB15 = ~LATBbits.LATB15;
}

bool LedRed_Status()
{
    return LATBbits.LATB15;
}

void toggle_LedYellow(void)
{
    LATBbits.LATB14 = ~LATBbits.LATB14;
}

bool LedYellow_Status()
{
    return LATBbits.LATB14;
}

void toggle_LedGreen(void)
{
    LATBbits.LATB13 = ~LATBbits.LATB13;
}

bool LedGreen_Status()
{
    return LATBbits.LATB13;
}