/* 
 * File:   pwm.c
 * Author: paola
 *
 * Created on 26 de julio de 2022, 9:32
 */

#include <xc.h>
#include <stdint.h
//#include <pic16f887.h>
#include "pwm_.h"
#include "pic16f887.h"



void pwm_init (uint8_t channel);
{
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC1 = 1;
    
    PR2 = PR2.VALUE;
    pwm_duty_cycle(512, 2);
    PIR1bits.TMR2IF = 0;
    T2CONbits.T2CKPS = 0b11;
    T2CONbits.TMR2ON = 1;
    while(TMR2IF == 0){}
    TRISCbits.TRISC2 = 0;
        
    if (channel == 1)
    {
        CCP1CON = 0b00001100;
        pwm_duty_cycle(512, 1);
    }
    
    else
    {
        CCP2CON = 0b00001100;
        pwm_duty_cycle(512, 2);  
    }
    
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC1 = 0;
    
}

void pwm_duty_cycle(uint16_t duty_cycle, uint8_t channel);
{
    if (channel == 1)
    {
        uint8_t temp_a = duty_cycle & 0b00000011;
        CCP1CONbits.DC1B = temp_a;
        uint16_t temp_b = duty_cycle >> 2;
        CCPR1L = temp_b;
        
    }
    else
    
        
        
}