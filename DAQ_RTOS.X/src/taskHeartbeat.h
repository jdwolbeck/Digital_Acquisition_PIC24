
#ifndef TASK_HEARTBEAT_H
#define	TASK_HEARTBEAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    void taskHeartbeat_Init(unsigned portBASE_TYPE uxPriority);
    void taskHeartbeat_Execute(void);
    void prvMainCoRoutine(CoRoutineHandle_t xHandle, unsigned portBASE_TYPE uxIndex);

#ifdef	__cplusplus
}
#endif

#endif	/* TASK_HEARTBEAT_H */

