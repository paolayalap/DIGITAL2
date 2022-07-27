/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __PWM__H_
#define	__PWM__H_

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "pic16f887.h"
#include "pwm_.h"

#define PR2_value 124

void pwm_init (uint8_t channel);
void pwm_duty_cycle(uint16_t duty_cycle);

#endif	/* __PWM__H_*/