/* 
 * File:   FinProj2func.h
 * Author: jakebaltierrez
 *
 * Created on May 15, 2024, 12:11 PM
 */

#ifndef FINPROJ2FUNC_H
#define	FINPROJ2FUNC_H

#include <xc.h> // must have this
#include "/Applications/microchip/xc8/v2.46/pic/include/proc/pic18f47k42.h"

#include "FinProj2Init.h"

volatile float distance;
volatile int time;
char totalDis[10];

int digital; // holds the digital value 
float voltage; // hold the analog value (volt))
char data[10];
float temp;

void LCD_Clear()
{
        LCD_Command(0x01); /* clear display screen */
}

void LCD_Char(char dat)
{
    ldata= dat;            /* Send data to LCD */  
    RS = 1;                /* Data Register is selected */
    EN=1;                  /* High-to-Low pulse on Enable pin to latch data */   
    NOP();
    EN=0;
    MSdelay(1);
}


void LCD_String(const char *msg)
{
    while((*msg)!= '\0')
    {       
      LCD_Char(*msg);
      msg++;    
        }
}

void LCD_String_xy(char row,char pos,const char *msg)
{
    char location=0;
    if(row<=1)
    {
        location=(0x80) | ((pos) & 0x0f); /*Print message on 1st row and desired location*/
        LCD_Command(location);
    }
    else
    {
        location=(0xC0) | ((pos) & 0x0f); /*Print message on 2nd row and desired location*/
        LCD_Command(location);    
    }  
    LCD_String(msg);

}

void trigPulse()
{
    trigPin = 1;
    __delay_us(10);
    trigPin = 0;
}
void backOff()
{
    LCD_String_xy(1,0,"TOO CLOSE");
    LCD_String_xy(2,0,"BACK AWAY");
    for(int m = 0; m < 5; m++)
    {   
        PORTAbits.RA2 = 1;  // e.g,blink a buzzer connected to  PORTAbits.RA2 for 5 times with a delay of __delay_ms(250)
       __delay_ms(250);
       PORTAbits.RA2 = 0;
       __delay_ms(250);
    }
    __delay_ms(10);
}

void inRange()
{    
    //LCD_String_xy(2,0,"DISTANCE: ");
    sprintf(totalDis,"%10f cm",distance);
    LCD_String_xy(2,0,totalDis);/*Send string data for printing*/

    __delay_ms(100);
}

void thankYou()
{
    LCD_String_xy(2,0,"THANK YOU");
    __delay_ms(100);
}

void sonicSen(void)
{
   
    //OSCCON = 0x72;
    //TRISA = 0b000000001;
    //WPUA = 0;
    trigPin = 0;
    T1CON = 0x80;
    //TMR1IF = 0;
    TMR1H = 0;      // timer high byte
    TMR1L = 0;      // timer low byte
    //TMR1CS = 0;
    //T1CKPS0 = 0;
    //T1CKPS1 = 0;
    
    
    
    
    while(1)
    {
        //LCD_Clear();
        LCD_String_xy(1,0,"STAY AWAY");
        //trigPin = 0;
        trigPulse();
        while(echoPin == 0);
        //TMR1 = 0;
        TMR1ON = 1;
        while(echoPin == 1);
        //time = TMR1;
        TMR1ON = 0;
// wont work timer voltage does not send signal needed
        ADCON0bits.GO = 1; //Start conversion
        while (ADCON0bits.GO); //Wait for conversion done
        time = (TMR1H*256) | (TMR1L);/*Combine 8-bit LSB and 2-bit MSB*/
        //distance = (time*((float)Vref/(float)(4096))); 
        //distance = (float)time;
        //distance = (((float)time * 34000000)/2);   //distance = (velocity * time)/2
        distance = ((float)time*1000);
//        if(time>2)
//        {
//            backOff();
//        }
//        if(time>=2 && time<=400)
//        {
//            inRange();
//        }
//        if(time<400)
//        {
//            thankYou();
//        }
        inRange();
    }
}

void checktemp(){
    if(temp >= 82){
        LCD_String_xy(1,0,"TOO HOT           ");
        PORTAbits.RA3 = 1;
        }
    if(temp < 81){
        LCD_String_xy(1,0,"Temperature: ");
        PORTAbits.RA3 = 0;
    }
}
    
void tempSens()
{       
    //OSCCON=0x72;                   /* Use Internal Oscillator with Frequency 8MHZ */ 
    LCD_Init();                    /* Initialize 16x2 LCD */
    ADC_Init();    
    LCD_String_xy(1,0,"Temperature: ");    /* Display string at location(row,location). */

    while (1) {
        ADCON0bits.GO = 1; //Start conversion
        while (ADCON0bits.GO); //Wait for conversion done
        digital = (ADRESH*256) | (ADRESL);/*Combine 8-bit LSB and 2-bit MSB*/
        voltage= digital*((float)Vref/(float)(4096));
        temp = (voltage - 0.4) * 30;
        //print on LCD 
        /*It is used to convert integer value to ASCII string*/
        sprintf(data,"%0.1f degF",temp);
        LCD_String_xy(2,4,data);/*Send string data for printing*/
        checktemp();
        MSdelay(150);
}
}

//emergency interrupt
void __interrupt(irq(IRQ_INT2),base(0x4008)) INT2_ISR(void){ // Defining Interrupt ISR 

    if(PORTBbits.RB2 == 1)
    { // Check if interrupt flag for INT2 is set to 1 - (note INT2 is your input)
        __delay_ms(200);
        while(PORTBbits.RB2 == 0){
            LCD_String_xy(1,0,"COOLING             ");
           __delay_ms(200);
            PORTAbits.RA3 = 1; 
        }

    }
        PIR7bits.INT2IF = 0;           // always clear the interrupt flag for INT0 when done               
        PORTAbits.RA3 = 0;        // turn off the buzzer on PORTAbits.RA5 
}

void test()
{ LCD_Init();                    /* Initialize 16x2 LCD */
    LCD_String_xy(1,0,"Jacob Baltierrez");    /* Display string at location(row,location). */
                                   /* This function passes string to display */
    LCD_String_xy(2,0,"is cool");   /*Display string at location(row,location). */
}

#endif	/* FINPROJ2FUNC_H */
