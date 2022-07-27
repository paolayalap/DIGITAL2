/* 
 * File:   osc_library.h
 * Author: paola
 *
 * Created on 22 de julio de 2022, 13:38
 */

#ifndef OSC_LIBRARY_H
#define	OSC_LIBRARY_H

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "osc_library.h"

void init_osc_MHz (uint8_t freq);

#endif	/* OSC_LIBRARY_H */

