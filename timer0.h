/* 
 * File:   tmr0.h
 * Author: paola
 *
 * Created on 26 de julio de 2022, 0:44
 */

#ifndef __TIMER0_H
#define	__TIMER0_H

#include <xc.h>
#include <stdint.h>
#include "timer0.h"

#define TMR0_VALUE 4

void tmr0_init(uint8_t prescaler);
void tmr0_reload(void);

#endif /* XC_HEADER_TEMPLATE_H */