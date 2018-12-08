#ifndef XC_LED_H
#define	XC_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>

void Int0_init(void);
void LedRed_On(void);
void LedRed_Off(void);
void toggle_LedRed(void);
void LedRed_Status(void);
void LedYellow_On(void);
void LedYellow_Off(void);
void toggle_LedYellow(void);
void LedYellow_Status(void);
void LedGreen_On(void);
void LedGreen_Off(void);
void toggle_LedGreen(void);
void LedGreen_Status(void);


#endif	/* XC_LED_H */

