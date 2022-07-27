/* 
 * File:   oscilador.c
 * Author: Paola Ayala Pineda
 *
 * Created on 20 de julio de 2022, 8:20
 */

//LIBRERIAS
#include <xc.h>
#include <stdint.h> //Se incluye la librería para "freq"
#include <pic16f887.h>
#include "osc.h"

//FUNCIONES
void init_osc_MHz (uint8_t freq)
{
    //Mediante un swtich para que el usuario puede decidir el valor del osc.
    switch(freq)
    {
        case 1:
            OSCCONbits.IRCF2 = 1; // 1MHz
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 0;
            break;
        case 2:
            OSCCONbits.IRCF2 = 1; // 2MHz
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 1;
            break;
        case 4:
            OSCCONbits.IRCF2 = 1; // 4MHz
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
        case 8:
            OSCCONbits.IRCF2 = 1; // 8MHz
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 1;
            break;
        default:
            OSCCONbits.IRCF2 = 1; // 4MHz
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
            
    }
    OSCCONbits.SCS = 1;     //se usa el reloj interno
}
