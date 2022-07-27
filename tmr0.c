/* 
 * File:   tmr0.c
 * Author: paola
 *
 * Created on 26 de julio de 2022, 1:09
 */

#include <xc.h>
#include <stdinr.h>
#include "timer0.h"

void tmr0_init(uint8_t prescaler)
{
    INTCONbits.T0IF = 1;
    
        switch(prescaler)
        {
                case 2:                     //prescaler de 2
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b000;
                    break;
                case 4:                     //prescaler de 4
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b001;
                    break;
                case 8:                     //prescaler de 8
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b010;
                    break;
                case 16:                    //prescaler de 16
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b011;
                    break;    
                case 32:                    //prescaler de 32
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b100;
                    break;    
                case 64:                    //prescaler de 64
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b101;
                    break;   
                case 128:                   //prescaler de 128
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b110;
                    break;
                case 256:                   //prescaler de 256
                    OPTION_REGbits.T0CS = 0;
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b111;
                    break;
                default                     //prescaler de 256
                    OPTION_REGbits.T0CS = 0; 
                    OPTION_REGbits.PSA = 0;
                    OPTION_REGbits.PS = 0b111;
                    break;
        }
    
    INCONbits.T0IF = 0;    // se limpia la bandera
}

void tmr0_reload(void)
{
    TMR0 = TMR0_VALUE;    
    TMR0IF = 0;
            
}
