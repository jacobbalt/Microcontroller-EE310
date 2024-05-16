/* 
 * File:   FinProj2Init.h
 * Author: jakebaltierrez
 *
 * Created on May 15, 2024, 12:12 PM
 */

#ifndef FINPROJ2INIT_H
#define	FINPROJ2INIT_H

#include <xc.h>
#include "/Applications/microchip/xc8/v2.46/pic/include/proc/pic18f47k42.h"
//#include "C:\Program Files\Microchip\xc8\v2.40\pic\include\proc\pic18f46k42"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

#define RS LATB0                   /* PORTD 0 pin is used for Register Select */
#define EN LATB1                   /* PORTD 1 pin is used for Enable */
#define ldata LATD                 /* PORTB is used for transmitting data to LCD */

#define LCD_Port TRISD              
#define LCD_Control TRISB

//#define trigPin PORTCbits.RC0
//#define echoPin PORTAbits.RA0

#define Vref 5.0 // voltage reference 
//#define Vref 5000 // lux reference 


void interruptInitialize (void){
    INTCON0bits.IPEN = 1; // Enable interrupt priority bit in INTCON0 (check INTCON0 register and find the bit)
    INTCON0bits.GIEH = 1; // Enable high priority interrupts using bits in INTCON0
    INTCON0bits.GIEL = 1; // Enable low priority interrupts using bits in INTCON0
    INTCON0bits.INT2EDG = 1; // Interrupt on rising edge of INT2 pin using bits in INTCON0
    IPR7bits.INT2IP = 1;  // Set the interrupt high priority (IP) for INT2 - INT2IP
    PIE7bits.INT2IE = 1; // Enable the interrupt (IE) for INT2

    PIR7bits.INT2IF = 0;   //Clear interrupt flag for INT2
  
    // Change IVTBASE by doing the following
    IVTBASEU = 0x00;  // Set IVTBASEU to 0x00 
    IVTBASEH = 0x40; // Set IVTBASEH to  0x40; 
    IVTBASEL = 0x08; // Set IVTBASEL to 0x08; 
}

void MSdelay(unsigned int val)
{
     unsigned int i,j;
        for(i=0;i<val;i++)
            for(j=0;j<165;j++);      /*This count Provide delay of 1 ms for 8MHz Frequency */
}

void LCD_Command(char cmd )
{
    ldata= cmd;            /* Send data to PORT as a command for LCD */   
    RS = 0;                /* Command Register is selected */
    EN = 1;                /* High-to-Low pulse on Enable pin to latch data */ 
    NOP();
    EN = 0;
    MSdelay(3); 
}



void LCD_Init()
{
    MSdelay(15);           /* 15ms,16x2 LCD Power on delay */
    LCD_Port = 0x00;       /* Set PORTB as output PORT for LCD data(D0-D7) pins */
    LCD_Control = 0x00;    /* Set PORTD as output PORT LCD Control(RS,EN) Pins */
    LCD_Command(0x01);     /* clear display screen */
    LCD_Command(0x38);     /* uses 2 line and initialize 5*7 matrix of LCD */
    LCD_Command(0x0c);     /* display on cursor off */
    LCD_Command(0x06);     /* increment cursor (shift cursor to right) */
}

void ADC_Init(void)
{
       //Setup ADC
    ADCON0bits.FM = 1;  //right justify
    ADCON0bits.CS = 1; //ADCRC Clock
    
    TRISAbits.TRISA0 = 1; //Set RA0 to input
    ANSELAbits.ANSELA0 = 1; //Set RA0 to analog
    // Added 
    ADPCH = 0x00; //Set RA0 as Analog channel in ADC ADPCH
    ADCLK = 0x00; //set ADC CLOCK Selection register to zero
    
    ADRESH = 0x00; // Clear ADC Result registers
    ADRESL = 0x00; 
    
    ADPREL = 0x00; // set precharge select to 0 in register ADPERL & ADPERH
    ADPREH = 0x00; 
    
    ADACQL = 0x00;  // set acquisition low and high byte to zero 
    ADACQH = 0x00;    
    
    ADCON0bits.ON = 1; //Turn ADC On 
}
//PORT initialization
void initial(void){
    PORTA = 0x00;
    LATA = 0x00;
    ANSELA = 0x00;
    TRISA = 0b00010001;
    //RA0 ACD output
    //RA3 Buzzer output
    
    PORTB = 0x00;
    LATB = 0x00;
    ANSELB = 0x00;
    TRISB = 0x01;
    //WPUB = 1; //enable weak pull ups for port b
    //LCD output
    
    //LCD output RB0, RB1
    //interrupt bit RB3
    
    PORTD = 0x00;
    LATD = 0x00;
    ANSELD = 0x00;
    TRISD = 0x00;
    //PORTD out only for LCD
    
//    PORTC = 0x00;
//    LATC = 0x00;
//    ANSELC = 0x00;
//    TRISC = 0x00;
//    

}
#endif	/* FINPROJ2INIT_H */
