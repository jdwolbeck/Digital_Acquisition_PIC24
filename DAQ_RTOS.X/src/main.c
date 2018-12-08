
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE

#include "FreeRTOS.h"
#include "croutine.h"
#include "task.h"

#include "../mcc_generated_files/system.h"
#include "../mcc_generated_files/pin_manager.h"

//RTOS tasks include
#include "app.h"
#include "taskHeartbeat.h"
#include "taskBlinky.h"
#include "taskUart.h"
#include "taskTimer.h"
#include "led.h"

#include "initialization.h"
/*****************************************************************************

    Private Macros

 *****************************************************************************/

/* The number of flash co-routines to create. */
#define mainNUM_FLASH_COROUTINES   (1)

/*****************************************************************************

    Private functions prototype

 *****************************************************************************/



// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
//Global variables
int btnCount = 0;       
char RXread = '_';     
int wait_ms = 500;  
int t_count = 0;
bool number_input = false;
bool pwm_enable = false;
char command_string[20];
int main( void )
{
    // initialize the device
    SYSTEM_Initialize();
    
    //=========================================================================
    //    Board initialization
    //=========================================================================
    App_init();

    //=========================================================================
    //    Set application's initial state
    //=========================================================================
    
    //=========================================================================
    //    Application Task initialization
    //=========================================================================
    taskBlinky_init();
    taskTimer_init();
    taskUart_init();
    Int0_init();

    //=========================================================================
    //    FreeRTOS scheduler
    //=========================================================================
    vTaskStartScheduler();

    /* If all is well then this line will never be reached.  If it is reached
    then it is likely that there was insufficient (FreeRTOS) heap memory space
    to create the idle task.  This may have been trapped by the malloc() failed
    hook function, if one is configured.
    */
    
    while (1)
    {
        // Add your application code
    }
    
    return -1;
}

/*******************************************************************************
 End of File
*/