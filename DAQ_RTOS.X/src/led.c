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

void LedRed_On(void)
{
    LATBbits.LATB15 = 1;
}

void LedRed_Off(void)
{
    LATBbits.LATB15 = 0;
}

void toggle_LedRed(void)
{
    LATBbits.LATB15 = ~LATBbits.LATB15;
}

void LedRed_Status(void)
{
    if(LATBbits.LATB15)
    {
        Nop();
        U1TXREG = 'R';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'N';
    }
    else
    {
        Nop();
        U1TXREG = 'R';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'F';
        U1TXREG = 'F';
    }
}

void LedYellow_On(void)
{
    LATBbits.LATB14 = 1;
}

void LedYellow_Off(void)
{
    LATBbits.LATB14 = 0;
}

void toggle_LedYellow(void)
{
    LATBbits.LATB14 = ~LATBbits.LATB14;
}

void LedYellow_Status(void)
{
    if(LATBbits.LATB14)
    {
        Nop();
        U1TXREG = 'Y';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'N';
    }
    else
    {
        Nop();
        U1TXREG = 'Y';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'F';
        U1TXREG = 'F';
    }
}

void LedGreen_On(void)
{
    LATBbits.LATB13 = 1;
}

void LedGreen_Off(void)
{
    LATBbits.LATB13 = 0;
}

void toggle_LedGreen(void)
{
    LATBbits.LATB13 = ~LATBbits.LATB13;
}

void LedGreen_Status()
{
    if(LATBbits.LATB13)
    {
        Nop();
        U1TXREG = 'G';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'N';
    }
    else
    {
        Nop();
        Nop();
        U1TXREG = 'G';
        U1TXREG = '_';
        U1TXREG = 'O';
        U1TXREG = 'F';
        U1TXREG = 'F';
    }
}