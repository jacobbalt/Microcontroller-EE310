//---------------------
// Title: Final Project
//---------------------
//Program Details: Build a safe box with user input code.
// 
//-------	
// Purpose: to learn how to interface different I/O ports using photo resistors,
//          buzzer, motor, and relay.
//
// File Dependencies / Libraries: None 
// Compiler: XC.8
// Author: JACOB BALTIERREZ
// Outputs: PORTD0,1,2,3,4,5,6,7; PORTB0,1; PORTA3
// Inputs: PORTB2, PORTA0
// Date: MAY 16, 2024
// Versions:
//       V1.0: 5/16/2024 - First Version: working edition 
//      
//	
//
//---------------------
// PIC18F46K42 Configuration Bit Settings

// 'C' source line config statements
#include <xc.h> // must have this
//#include "tmr0.h"
#include "/Applications/microchip/xc8/v2.46/pic/include/proc/pic18f47k42.h"
#include "FinProj2Init.h"
#include "FinProj2func.h"
#include "Cheader.h"

void main()
{
    LCD_Init();
    ADC_Init();
    initial();
    interruptInitialize();
    
    while(1)
    {
        //sonicSen();
        //test();
        tempSens();
    }
}
