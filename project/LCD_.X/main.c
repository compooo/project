/*
 * File:   main.c
 * Author: ahmed
 *
 * Created on December 16, 2021, 3:58 PM
 */


#include <avr/io.h>
#include "mLCD.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "mTimer.h"
#include "IO.h"

int main(void) {
    init_LCD_4bit();
    init_PWM(OC0_clear);
    Duty_Cycle(200);
    Select_prescaler();
    int symbol_1, symbol_2, symbol_3, high, period;
    float duty_cycle;
    TCCR1A = 0;
    TCNT1 = 0;
    TIFR = (1 << ICF1);
    TCCR1B = 0x41; //raising edge, No_prescaler
    while ((TIFR & (1 << ICF1)) == 0);
    //waiting event occurs
    symbol_1 = ICR1; // take symbol
    TIFR = (1 << ICF1); // clear flag

    TCCR1B = 0x01; //falling edge
    while ((TIFR & (1 << ICF1)) == 0);
    //waiting event occurs
    symbol_2 = ICR1; // take symbol
    TIFR = (1 << ICF1); // clear flag

    TCCR1B = 0x41; //raising Edge
    while ((TIFR & (1 << ICF1)) == 0);
    //waiting event occurs
    symbol_3 = ICR1; // take symbol
    TIFR = (1 << ICF1); // clear flag

    TCCR1B = 0; //stop
    if ((symbol_1 < symbol_2) && (symbol_2 < symbol_3)) {
        high = symbol_2 - symbol_1;
        period = symbol_3 - symbol_1;
        long freq = F_CPU / period;
        long time = 1000000/freq;
        duty_cycle = ((float) high / (float) period)*100;
        char write[5] = "Freq:";
        LCD_Write_Str_4bit(write);
        goto_XY_4bit(0, 5);
        LCD_Write_Num_4bit(freq);
        goto_XY_4bit(0, 10);
        char unit[20] = "HZ";
        LCD_Write_Str_4bit(unit);
        goto_XY_4bit(1,0);
        char write2[5] = "Duty:";
        LCD_Write_Str_4bit(write2);
        goto_XY_4bit(1, 5);
        LCD_Write_Num_4bit(duty_cycle);
        goto_XY_4bit(1,7);
        char unit1[1] = "%";
        LCD_Write_Str_4bit(unit1);
        goto_XY_4bit(1,9);
        char time1[2]="T:";
        LCD_Write_Str_4bit(time1);
        goto_XY_4bit(1,11);
        LCD_Write_Num_4bit(time);
    } else {
        LCD_CLEAR_4bit();
    }
    while (1){
        
    }
}
