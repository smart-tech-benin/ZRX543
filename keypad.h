/**
    @firme: Smart Technology Benin
    @authpr: AMOUSSOU Z. Kenneth
    @Date: 15/08/2018
*/

#ifndef KEYPAD_H
#define KEYPAD_H

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define R1 2
#define R2 3
#define R3 4
#define R4 5

#define C1 6
#define C2 7
#define C3 8
#define C4 9

#define ROW_SIZE 4
#define COL_SIZE 4

#define KEY_0 '0'
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_A 'A'
#define KEY_B 'B'
#define KEY_C 'C'
#define KEY_D 'D'
#define KEY_STAR '*'
#define KEY_HASH '#'

class Keypad{
    public:
        Keypad()
        char read();                                // Read keypad
        void setDebounceTime(unsigned int time);    // Set debounce time
    
    private:
        unsigned int debounceTime;
        uint8_t row[ROW_SIZE];
        uint8_t col[COL_SIZE];
};

#endif
