#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "global.h"
#include "application.h"
#include "led.h"

void execute_command(void)
{
    if(strcmp(RXstring, "ledr0") == 0)
    {
        LedRed_Off();
    }
    else if(strcmp(RXstring,"ledr1") == 0)
    {
        LedRed_On();
    }
    else if(strcmp(RXstring,"rledr") == 0)
    {
        LedRed_Status();
    }
    else if(strcmp(RXstring,"pwm0") == 0)
    {
        pwm_enable = false;
        LedGreen_Off();
    }
    else if(strcmp(RXstring,"pwm1") == 0)
    {
        number_input = true;
        strcpy(command_string, "pwm1");
    }
    else if(strcmp(RXstring,"tmron") == 0)
    {
        number_input = true;
        strcpy(command_string, "tmron");
    }
    else if(strcmp(RXstring,"tmroff") == 0)
    {
        tmr_enable = false;
        LedYellow_Off();
    }
    else if(strcmp(RXstring,"tmrs") == 0)
    {
        LedYellow_Status();
    }
    else if(strcmp(RXstring,"adc1") == 0)
    {
        char buf[10];
        int ADCValue0 = 0;
        IFS0bits.AD1IF = 0;
        AD1CON1bits.ASAM = 1;

        while(!IFS0bits.AD1IF){};
        AD1CON1bits.ASAM = 0;
        ADCValue0 = ADC1BUF0;
        
        sprintf(buf, "%1d", ADCValue0);
        uart_print(buf, 1);
    }
    else if(strcmp(RXstring, "adc2") == 0)
    {
        char buf[10];
        int ADCValue1 = 0;
        IFS0bits.AD1IF = 0;
        AD1CON1bits.ASAM = 1;

        while(!IFS0bits.AD1IF){};
        AD1CON1bits.ASAM = 0;
        ADCValue1 = ADC1BUF1;
        
        sprintf(buf, "%1d", ADCValue1);
        uart_print(buf, 2);
    }
    else if(strcmp(RXstring, "adc3") == 0)
    {
        char buf[10];
        int ADCValue2 = 0;
        IFS0bits.AD1IF = 0;
        AD1CON1bits.ASAM = 1;

        while(!IFS0bits.AD1IF){};
        AD1CON1bits.ASAM = 0;
        ADCValue2 = ADC1BUF2;
        
        sprintf(buf, "%1d", ADCValue2);
        uart_print(buf, 3);
    }
    else
        toggle_LedRed();
    
    strcpy(RXstring, "\0");
}

void execute_number(void)
{
    number_input = false;
    float num = atoi(RXstring);
    if(strcmp(command_string,"pwm1") == 0)
    {
        pwm_enable = true;
        if(num >= 0 && num <= 100000)
        {
            wait_ms = (250 / num);
        }
    }
    else if(strcmp(command_string,"tmron") == 0)
    {
        if(num >= 0 && num <= 100000)
        {
            LedYellow_On();
            tmr_enable = true;
            t_count = (num * 10) + 1;
        }
    }
    strcpy(command_string, "\0");
}

void uart_print(char buf[], int select)
{
    int i;
    char tempstr[2];
    if(select == 1)
    {
        tempstr[0] = 'a';
        tempstr[1] = '\0';
        strcat(buf,tempstr);
    }
    else if(select == 2)
    {
        tempstr[0] = 'b';
        tempstr[1] = '\0';
        strcat(buf,tempstr);
    }
    else
    {
        tempstr[0] = 'c';
        tempstr[1] = '\0';
        strcat(buf,tempstr);
    }
    for(i = 0; i < strlen(buf); i++)
    {
        U1TXREG = buf[i];
    }
    
}