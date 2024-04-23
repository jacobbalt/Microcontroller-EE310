//---------------------
// Title: ASSIGNMENT 8
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
// Outputs: PORTD0,1,2,3,4,5,6,7; PORTA2,6,7
// Inputs: PORTB0,1,2,3
// Date: APRIL 22, 2024
// Versions:
//       V1.0: 4/22/2024 - First Version: first working edition no Header Files
//      
//	
//
//---------------------
// PIC18F46K42 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h> // must have this
//#include "../../../../../Program Files/Microchip/xc8/v2.40/pic/include/proc/pic18f46k42.h"
#include "/Applications/microchip/xc8/v2.46/pic/include/proc/pic18f47k42.h"
//#include "C:\Program Files\Microchip\xc8\v2.40\pic\include\proc\pic18f46k42"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Cheader.h"
#include "SafeboxInitial.h"
#include "Safeboxfuctions.h"

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

//static int secretCode = 0x31;
//volatile char sevseg;
//volatile char inCode;
//static char secretCode = 0x11;
////char userIn;

////PORT initialization
//void initial(void){
//    PORTA = 0x00;
//    LATA = 0x00;
//    ANSELA = 0x00;
//    TRISA = 0x00;
//    //power on out RA2
//    //motor on out RA6
//    //buzzer out RA7
//    
//    PORTB = 0x00;
//    LATB = 0x00;
//    ANSELB = 0x00;
//    TRISB = 0xFF;
//    WPUB = 1; //enable weak pull ups for port b
//    //photo resistor input1 RB3
//    //photo resistor input2 RB1
//    //switch to confirm input RB2
//    //interrupt bit RB0
//    
//    PORTD = 0x00;
//    LATD = 0x00;
//    ANSELD = 0x00;
//    TRISD = 0x00;
//    //PORTD out only for 7seg
//    
//
//}

//void powerOn(void){
////        PORTA = 0x00;
////        LATA = 0x00;
////        ANSELA = 0x00;
////        TRISA = 0x01;
//
//        __delay_ms(200);
//    //while (PORTBbits.RB7 != 1){
//        
//    //}
//            PORTAbits.RA2 = 1;
//        }
//
////seven segment for input
//char sevenSeg(void){
////unsigned char sevseg = 0;
//
////PORTD = 0x00;
////LATD = 0x00;
////ANSELD = 0x00;
////TRISD = 0x00;
//
////for(7seg)
//    PORTD = 0x3F;
//
//sevseg = sevseg + 1;
//
//    if(sevseg == 1){
//        PORTD = 0x06;
//    }
//    if(sevseg == 2){
//        PORTD = 0x5B;
//    }
//    if(sevseg==3){
//        PORTD = 0x4F;
//    }
//    if(sevseg == 4){
//        PORTD = 0x66;
//    }
//    if(sevseg == 5){
//        PORTD = 0x6D;
//    }
//    if(sevseg == 6){
//        PORTD = 0x7D;
//    }
//    if(sevseg == 7){
//        PORTD = 0x07;
//    }
//    if(sevseg == 8){
//        PORTD = 0x7F;
//    }
//    if(sevseg == 9){
//        PORTD = 0x67;
//    }
//    if(sevseg == 10){
//        PORTD = 0x77;
//    }
//    if(sevseg == 11){
//        PORTD = 0x7C;
//    }
//    if(sevseg == 12){
//        PORTD = 0x39;
//    }
//    if(sevseg == 13){
//        PORTD = 0x5E;
//    }
//    if(sevseg == 14){
//        PORTD = 0x79;
//    }
//    if(sevseg == 15){
//        PORTD = 0x71;
//    }
//    if(sevseg == 15){
//        sevseg = 0;
//    }
////return sevseg;
//}
//
////secret code for box
////char secretCode(char secretIn){
////    char secret1 = 0x03;
////    char secret2 = 0x01;
////    
////    //secret1 = 0x03;
////    //secret2 = 0x01;
////    secretIn = (secret1 * 16) + secret2;
////    return secretIn;
////}
//
//
////touch less switch input (photo resistors)
//char notouchIn (void){
//   char inputnum1 = 0;
//   char inputnum2 = 0;
//   //char totIn = 0;
////   PORTB = 0x00;
////   LATB = 0x00;
////   ANSELB = 0x00;
////   TRISB = 0b00000111;
//   
//   while(PORTBbits.RB2 != 1){
//              __delay_ms(200);
//      while(PORTBbits.RB3 == 1){
//            __delay_ms(700);
//            inputnum1 = inputnum1 + 1;
//            sevenSeg();
//      }
//   }
//   //inCode = inputnum1 * 16;
//   sevseg = 0;
//   __delay_ms(1000);
//   
//   while(PORTBbits.RB2 !=1){
//       __delay_ms(200);
//        while(PORTBbits.RB1 == 1){
//            __delay_ms(700);
//            inputnum2 = inputnum2 + 1;
//            sevenSeg();
//        }
//   }
//    //__delay_ms(250);
//   inCode = (inputnum1 * 16)+ inputnum2;
//   //totIn = inCode;
//   //return 2;
//}
//
////check if input is correct
//char checkInput(char secretCode){
//    
//        //secretCode = 0x11;
//        if(inCode == secretCode){
//            PORTAbits.RA5 = 1;
//            __delay_ms(2000);
//            PORTAbits.RA5 = 0;
//        }
//        if(inCode != secretCode){
//            PORTAbits.RA3 = 1;
//            __delay_ms(500);
//            PORTAbits.RA3 = 0;
//        }
////        if(inCode == secretCode){
////            //correct! turn on motor to open box
////            PORTAbits.RA7 = 1;
//////            __delay_ms(2000);
//////            PORTAbits.RA7 = 0;
////        } else {
////        //if(inCode != secretCode){
////            //incorrect buzzer
////            PORTAbits.RA6 = 1;
////            //__delay_ms(1000);
////            //PORTAbits.RA6 = 0;
////        }
//        //switch to one port
//        return secretCode;
//        
//}
//
////emergency interrupt
//void __interrupt(irq(IRQ_INT0),base(0x4008)) INT0_ISR(void){ // Defining Interrupt ISR 
//
//    if(PORTBbits.RB0 == 1)
//    { // Check if interrupt flag for INT0 is set to 1 - (note INT0 is your input)
//        __delay_ms(200);
//        for(int m = 0; m < 5; m++)
//        {   // if so, do something
//            PORTAbits.RA3 = 1;  // e.g,blink a buzzer connected to  PORTAbits.RA6 for 5 times with a delay of __delay_ms(250)
//           __delay_ms(250);
//           PORTAbits.RA3 = 0;
//           __delay_ms(250);
//        }
//    }
//        PIR1bits.INT0IF = 0;           // always clear the interrupt flag for INT0 when done               
//        PORTAbits.RA3 = 0;        // turn off the buzzer on PORTAbits.RA5 
//}
//void interruptInitialize (void){
//    INTCON0bits.IPEN = 1; // Enable interrupt priority bit in INTCON0 (check INTCON0 register and find the bit)
//    INTCON0bits.GIEH = 1; // Enable high priority interrupts using bits in INTCON0
//    INTCON0bits.GIEL = 1; // Enable low priority interrupts using bits in INTCON0
//    INTCON0bits.INT0EDG = 1; // Interrupt on rising edge of INT0 pin using bits in INTCON0
//    IPR1bits.INT0IP = 1;  // Set the interrupt high priority (IP) for INT0 - INT0IP
//    PIE1bits.INT0IE = 1; // Enable the interrupt (IE) for INT0
//
//    PIR1bits.INT0IF = 0;   //Clear interrupt flag for INT01
//  
//    // Change IVTBASE by doing the following
//    IVTBASEU = 0x00;  // Set IVTBASEU to 0x00 
//    IVTBASEH = 0x40; // Set IVTBASEH to  0x40; 
//    IVTBASEL = 0x08; // Set IVTBASEL to 0x08; 
//}

void main(void){
    
    initial();
    powerOn();
    interruptInitialize();
    //secretCode(secretIn);
    notouchIn();
    checkInput(secretCode); 
}
