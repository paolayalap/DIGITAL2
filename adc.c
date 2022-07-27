/* 
 * File:   adc.c
 * Author: Paola Andrea Ayala Pineda 
 *
 * Created on 20 de julio de 2022, 9:02
 */

//LIBRERIAS
#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "adc_.h"

//FUNCIONES
void adc_init (uint8_t adc_cs, uint8_t vref_plus, uint8_t vref_minus)
{
    ADCON1bits.ADFM = 1;    //justificado a la derecha
    
    switch(adc_cs)
    {
        case 2:
            ADCON0bits.ADCS = 0b00; // Fosc/2
            break;
            
        case 8:
            ADCON0bits.ADCS = 0b01; // Fosc/8
            break;
            
        case 32:
            ADCON0bits.ADCS = 0b10; // Fosc/32
            break;
            
        case 0:
            ADCON0bits.ADCS = 0b11; // Fosc/32
            break;
            
        default:
            ADCON0bits.ADCS = 0b11; // Frc
            break;
    }
    
/*
    if (ADCON1bits.ADFM = 0) // Justificación a la izquierda
    {
        switch(vref_plus)
        {
            case 1:
                ADCON1bits.VCFG0 = 0;       // Vss como referencia
                break;
            case 2:
                ADCON1bits.VCFG0 = 1;       // externo
                break;
        }
    }
    
    else // Justificación a la derecha
    {
        switch(vref_minus)
        {
            case 1:
                ADCON1bits.VCFG1 = 0;       // Vdd como referencia
                break;
            case 2:
                ADCON1bits.VCFG1 = 0;       // externo
                break;
        }
    }  */
    
    ADCON1bits.VCFG1 = vref_plus;
    ADCON1bits.VCFG0 = vref_minus;
    
}

void adc_start(uint8_t channel)
{
        ADCON0bits.CHS = channel;

        switch(channel)
        {
            case 0:
                ADCON0bits.CHS = 0b0000;
                break;
            case 1:
                ADCON0bits.CHS = 0b0001;
                break;


        ADCON0bits.GO = 1;
    }
}

void adc_read(void)
{
        uint16_t temp_adc = 0;
        

            temp_adc = ADRESH << 8;

            temp_adc = ADRESL;

            ADIF = 0;

        return;

}
    


    /*uint16_t adc_read(void)
    {
        if uint16_t temp_adc = 0;
        

            temp_adc = ADRESH << 8;

            temp_adc = ADRESL;

            ADIF = 0;

        return;

    }
    
}
     */
        
    