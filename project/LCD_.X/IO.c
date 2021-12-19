#include<avr/io.h>
#include"IO.h"

void setPortDir(int portNum, int state) {
    switch (portNum) {
        case _PA:
            DDRA = state ? 0xFF : 0x00;
            break;
        case _PB:
            DDRB = state ? 0xFF : 0x00;
            break;
        case _PC:
            DDRC = state ? 0xFF : 0x00;
            break;
        case _PD:
            DDRD = state ? 0xFF : 0x00;
            break;
        default:
            DDRA = 0;
            DDRB = 0;
            DDRC = 0;
            DDRD = 0;
    }
}

void setPortData(int portNum, int dataOut) {
    switch (portNum) {
        case _PA:
            PORTA = dataOut;
            break;
        case _PB:
            PORTB = dataOut;
            break;
        case _PC:
            PORTC = dataOut;
            break;
        case _PD:
            PORTD = dataOut;
            break;
        default:
            DDRA = 0;
            DDRB = 0;
            DDRC = 0;
            DDRD = 0;
    }
}

void setPinDir(int portNum, int pinNum, int state) {
    if (state) {
        switch (portNum) {
            case _PA:
                DDRA |= (1 << pinNum);
                break;
            case _PB:
                DDRB |= (1 << pinNum);
                break;
            case _PC:
                DDRC |= (1 << pinNum);
                break;
            case _PD:
                DDRD |= (1 << pinNum);
                break;
        }
    } else {
        switch (portNum) {
            case _PA:
                DDRA &= ~(1 << pinNum);
                break;
            case _PB:
                DDRB &= ~(1 << pinNum);
                break;
            case _PC:
                DDRC &= ~(1 << pinNum);
                break;
            case _PD:
                DDRD &= ~(1 << pinNum);
                break;
        }
    }
}
void setPinData(int portNum, int pinNum, int data){
    if (data) {
        switch (portNum) {
            case _PA:
                PORTA |= (1 << pinNum);
                break;
            case _PB:
                PORTB |= (1 << pinNum);
                break;
            case _PC:
                PORTC |= (1 << pinNum);
                break;
            case _PD:
                PORTD |= (1 << pinNum);
                break;
        }
    } else {
        switch (portNum) {
            case _PA:
                PORTA &= ~(1 << pinNum);
                break;
            case _PB:
                PORTB &= ~(1 << pinNum);
                break;
            case _PC:
                PORTC &= ~(1 << pinNum);
                break;
            case _PD:
                PORTD &= ~(1 << pinNum);
                break;
        }
    }
}
