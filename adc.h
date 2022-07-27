
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ADC_H_
#define	__ADC_H_

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "adc.h"

void adc_init (uint8_t adc_cs, uint8_t vref_plus, uint8_t vref_minus);
void adc_start(uint8_t channel);

#endif	/* __ADC_H_