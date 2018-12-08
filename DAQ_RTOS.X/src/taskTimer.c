#include <stdlib.h>

#include "FreeRTOS.h"
#include "timers.h"
#include "task.h"
#include "taskTimer.h"
#include "global.h"
#include "led.h"

#include "../mcc_generated_files/pin_manager.h"


#define taskPRIORITY        1
#define taskSTACK_SIZE      512

/*****************************************************************************

    Private functions prototype

*****************************************************************************/
static portTASK_FUNCTION(vTimerTask, pvParameters);

/*****************************************************************************

    FreeRTOS Task implementation

*****************************************************************************/
static inline void vCreatNewTasks(unsigned portBASE_TYPE uxPriority)
{
    xTaskCreate(vTimerTask, (char const*)"taskName", (uint16_t)taskSTACK_SIZE/(uint16_t)(2), NULL, uxPriority, (TaskHandle_t *) NULL );
}

/*****************************************************************************

    Public functions implementation.

*****************************************************************************/
void taskTimer_init(void)
{
    vCreatNewTasks(taskPRIORITY);
}

static portTASK_FUNCTION(vTimerTask, pvParameters)
{
    /* Just to stop compiler warnings. */
    (void) pvParameters;

    //===========================================
    //Task entrance
    //===========================================
    while(1)
    {
        if(t_count == 1)
        {
            LedYellow_Off();
        }
        else if(t_count != 0)
        {
            vTaskDelay(48);
            t_count = t_count - 1;
        }
        vTaskDelay(2);
    }
}