#ifndef XC_LED_H
#define	XC_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>

void Int0_init(void);
void toggle_LedRed(void);
bool LedRed_Status(void);
void toggle_LedYellow(void);
bool LedYellow_Status(void);
void toggle_LedGreen(void);
bool LedGreen_Status(void);


#endif	/* XC_LED_H */

