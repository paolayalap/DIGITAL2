/* 
 * File:   main.c
 * Author: Paola Ayala Pineda
 * 
 * Este programa est� dise�ado con el fin de repasar las configuracion del 
 * TMR0, PWM y ADC. 
 *
 * Created on 20 de julio de 2022, 8:06
 */


// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


#include <xc.h>
#include <stdint.h>
#include "osc.h"
#include "adc_.h"
#include "pwm_.h"
#include "timer0.h"

//PROTOTIPO DE FUNCIONES
void initPorts(void);
void initTMR0(void);


//VARIABLES
uint16_t contador = 0;


//INTERRUPCIONES
void __interrupt() isr (void)
{
    if(TMR0IF)
    {
        void tmr0_reload(void);
        //TMR0IF = 0;
        //TMR0 = 4;
        contador++; //incrementa la variable de contador cada 0.5 ms
    }
}


//CONFIGURACION PRINCIPAL
void main (void)

{
    init_osc_MHz(4);
    tmr0_init(128);
    /*while(1)
    {
        if (contador>=1000)
        {
            PORTB++;
            contador = 0;
            
        }
    }
    //init_osc_MHz(4);
    //adc_init(1);*/
    return;
}

//INICIAR EL PUERTO
void setup(void){
    ANSEL = 0;
    ANSELH = 0b00000000;
}