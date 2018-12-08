#include <xc.h>
#include "initialization.h"

void App_init(void)
{
    Gpio_init();
    Adc_init();
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

void Adc_init(void)
{
    AD1CON1 = 0;                //Control Register 1
    AD1CON1bits.SSRC = 0x7;     //Internal counter triggers conversion
    
    AD1CON2 = 0x0000;           //Control Register 2
    AD1CON2bits.SMPI = 0b00010; //Cause interrupt (AD1IF) at the completion of every 3 samples
    AD1CON2bits.CSCNA = 1;      //Scan inputs are selected by AD1CSSL as MUX A inputs
    
    AD1CON3 = 0;                //Control Register 3
    AD1CON3bits.SAMC = 0b01111; //Sample time = 1Tad
    
    AD1CSSL = 0x0112;           //Scan AN8
    AD1CON1bits.ADON = 1;       //Turn on ADC
}