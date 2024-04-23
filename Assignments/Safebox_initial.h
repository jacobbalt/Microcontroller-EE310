/* 
 * File:   SafeboxInitial.h
 * Author: jakebaltierrez
 *
 * Created on April 20, 2024, 1:35 PM
 */


//PORT initialization
void initial(void){
    PORTA = 0x00;
    LATA = 0x00;
    ANSELA = 0x00;
    TRISA = 0x00;
    //power on out RA2
    //motor on out RA6
    //buzzer out RA7
    
    PORTB = 0x00;
    LATB = 0x00;
    ANSELB = 0x00;
    TRISB = 0xFF;
    WPUB = 1; //enable weak pull ups for port b
    //photo resistor input1 RB3
    //photo resistor input2 RB1
    //switch to confirm input RB2
    //interrupt bit RB0
    
    PORTD = 0x00;
    LATD = 0x00;
    ANSELD = 0x00;
    TRISD = 0x00;
    //PORTD out only for 7seg
    

}

//#ifndef SAFEBOXINITIAL_H
//#define	SAFEBOXINITIAL_H
//
//#ifdef	__cplusplus
//extern "C" {
//#endif
//    
//initialize functions

//initialize power on
    
//initialize secret code

//initialize touch less switch input
    
//initialize motor
    
//initialize buzzer
    
//initialize interrupt
    
//initialize seven segment



//#ifdef	__cplusplus
//}
//#endif
//
//#endif	/* SAFEBOXINITIAL_H */

