/*
 * File:   osc_library.c
 * Author: andre
 *
 * Created on July 20, 2022, 8:09 AM
 * Hardware:    
 */

#include <xc.h>
#include <stdint.h>
#include "osc_library.h"

void init_osc_MHz (uint8_t freq)
{ 
    switch(freq)
    {
        case 1:                                             // 1MHz OSC FREQ
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            break;
        case 2:                                             // 2MHz OSC FREQ
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 1;
            break;
        case 4:                                             // 4MHz OSC FREQ
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 0;
            break;
        case 8:                                             // 8MHz OSC FREQ
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 1;
            break;
        default:
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            break;            
    }
}