#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "FreeRTOS.h"
#include "timers.h"
#include "task.h"
#include "taskUart.h"
#include "led.h"

#include "../mcc_generated_files/pin_manager.h"
#include "global.h"
#include "application.h"

#define taskPRIORITY        0
#define taskSTACK_SIZE      512

/*****************************************************************************

    Private functions prototype

*****************************************************************************/
static portTASK_FUNCTION(vUartTask, pvParameters);

/*****************************************************************************

    FreeRTOS Task implementation

*****************************************************************************/
static inline void vCreatNewTasks(unsigned portBASE_TYPE uxPriority)
{
    xTaskCreate(vUartTask, (char const*)"taskName", (uint16_t)taskSTACK_SIZE/(uint16_t)(2), NULL, uxPriority, (TaskHandle_t *) NULL );
}

/*****************************************************************************

    Public functions implementation.

*****************************************************************************/
void taskUart_init(void)
{
    vCreatNewTasks(taskPRIORITY);
    U1MODE = 0x0000;//(0x8008 & ~(1<<15));//0x0000;
    U1STA = 0x0000;
        
    RPINR18bits.U1RXR = 3; //Set RB3 as U1RX
    RPOR2bits.RP4R = 3;  //Set RB4 as U1TX
    IFS0bits.U1RXIF = 0; //Clear RX interrupt Flag
    IPC2bits.U1RXIP = 3; //Priority of RX set to 3
    IEC0bits.U1RXIE = 1; //RX interrupt enabled    
    
    //Baud_Rate = 9600; Frequency = 4MHz; U2BRG = 25;
    U1BRG = (((4000000/9600)/16)-1); //Calculate baud rate registers value
    U1MODEbits.UARTEN = 1;  //UART1 enable    
    U1STAbits.UTXEN = 1;    //Enable
}

char RXstring[20];
static portTASK_FUNCTION(vUartTask, pvParameters)
{
    /* Just to stop compiler warnings. */
    (void) pvParameters;

    //===========================================
    //Task entrance
    //===========================================
    char tempstr[2];
    while(1)
    {
        if(RXread != '_')
        {
            switch(RXread)
            {
                case '#':
                    if(number_input == true)
                        execute_number();
                    else
                        execute_command();
                    break;
                case '-':
                    execute_command();
                    break;
                default:
                    tempstr[0] = RXread;
                    tempstr[1] = '\0';
                    strcat(RXstring,tempstr);
                    break;
            }
            RXread = '_';
        }
    }
}
