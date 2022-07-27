
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __OSCILADOR_H_
#define	__OSCILADOR_H_

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "oscilador.h"

void init_osc_MHz (uint8_t freq);

#endif	/* __OSCILADOR_H_ */

