/* 
 * File:   IO.h
 * Author: ahmed
 *
 * Created on December 16, 2021, 4:00 PM
 */

#ifndef IO_H
#define	IO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define F_CPU  16000000UL
#define _PA    0
#define _PB    1
#define _PC    2
#define _PD    3

#define ON     1
#define OFF    0
#define OUT    1
#define IN     0
void setPortDir(int portNum, int state);
void setPortData(int portNum, int dataOut);
void setPinDir(int portNum, int pinNum, int state);
void setPinData(int portNum, int pinNum, int data);

#endif	/* IO_H */

