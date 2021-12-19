/* 
 * File:   mTimer.h
 * Author: ahmed
 *
 * Created on December 16, 2021, 4:00 PM
 */

#ifndef MTIMER_H
#define	MTIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define Stop_Timer      0
#define No_Prescaler    1
#define Prescaler_8     2
#define Prescaler_64    3
#define Prescaler_256   4
#define Prescaler_1024  5
#define Falling_Edge    6
#define Rising_Edge     7  
    
#define Timer0_CLk      Prescaler_8    
    
#define OC0_dis     0
#define OC0_clear   1
#define OC0_set     2
    
void init_PWM(int Wave);
//Duty Cycle = (2*(255-OCR0)) / (255*2)
void Duty_Cycle(char Compare_Match);
void Select_prescaler();


#endif	/* MTIMER_H */

