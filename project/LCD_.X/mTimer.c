#include "mTimer.h"
#include <avr/io.h>
#include "IO.h"

void init_PWM( int Wave){     
    setPinDir(_PB, PB3, OUT);    //Set OCO Output (PB3)
    TCCR0 |= (1<<WGM00)| (1<<WGM01);     //Set Fast Mode
    switch(Wave){
        case OC0_dis:
            TCCR0 |= 0x00;
            break;
        case OC0_clear:
            TCCR0 |= (1<<COM01);
            break;
        case OC0_set:
            TCCR0 |= ((1<<COM01) | (1<<COM00));
            break;
        default:
            break;
            
   
    }   //Select Wave Generation
}
void Select_prescaler(){
    TCCR0 |= Timer0_CLk;
     /*switch(Prescaler){
        case Stop_Timer:
            TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));
            break;
        case No_Prescaler:
            TCCR0 |= (1<<CS00);
            break;
        case Prescaler_8:
            TCCR0 |=(1<<CS01);
            break;
        case Prescaler_64:
            TCCR0 |=(1<<CS01)|(1<<CS00);
            break;
        case Prescaler_256:
            TCCR0 |=(1<<CS02);
            break;
        case Prescaler_1024:
            TCCR0 |=((1<<CS02)|(1<<CS00));
            break;
        case Falling_Edge:
            TCCR0 |=((1<<CS02)|(1<<CS01));
            break;
        case Rising_Edge:
            TCCR0 |=((1<<CS02)|(1<<CS01)|(1<<CS00));
            break;
        default:
            break;
    }   //Set The Pre_scaler*/
}
//Duty Cycle = (2*(255-OCR0)) / (255*2) phase correct
void Duty_Cycle(char Compare_Match){
    //Compare_Match = ADC_out();        //controlling with ADC
    OCR0 = Compare_Match;
    //OCR0 = 255        Low Speed
    //OCR0 = 191        25% speed
    //OCR0 = 127        50% speed
    //OCR0 = 64         75% speed
    //OCR0 = 0          Max Speed
}