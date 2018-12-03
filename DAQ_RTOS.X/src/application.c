#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "application.h"
#include "led.h"

void execute_command(void)
{
    if(strcmp(RXstring,"tledr") == 0)
    {
        toggle_LedRed();
    }
    else if(strcmp(RXstring,"tledy") == 0)
    {
        toggle_LedYellow();
    }
    else if(strcmp(RXstring,"tledg") == 0)
    {
        toggle_LedGreen();
    }
    else if(strcmp(RXstring,"pwmw") == 0)
    {
        number_input = true;
        strcpy(command_string, "pwmw");
    }
    else if(strcmp(RXstring,"tmrd") == 0)
    {
        toggle_LedGreen();
    }
    else if(strcmp(RXstring,"tmron") == 0)
    {
        toggle_LedGreen();
    }
    else if(strcmp(RXstring,"adc1") == 0)
    {
        toggle_LedGreen();
    }
    else
        toggle_LedRed();
    
    strcpy(RXstring, "\0");
}

void execute_number(void)
{
    number_input = false;
    int num = atoi(RXstring);
    if(strcmp(command_string,"pwmw") == 0)
    {
        if(num >= 0 && num <= 100000)
        {
            wait_ms = num;
        }
    }
    strcpy(command_string, "\0");
}