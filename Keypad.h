/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 15/08/2018
    @version: 1.0
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

#define NONE '-'

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

class Keypad
{
    public:
        Keypad();
        ~Keypad();
        void begin();
        char read();                                // Read keypad
        void setDebounceTime(unsigned int time);    // Set debounce time
        String readPassword(char start = '*', char end = '#', unsigned int timeout = 15000); // Read keypad
    
    private:
        unsigned int debounceTime;
        uint8_t row[ROW_SIZE] = { R1, R2, R3, R4 };;
        uint8_t col[COL_SIZE] = { C1, C2, C3, C4 };;
        uint8_t pad[ROW_SIZE][COL_SIZE] = {     \
           { KEY_1, KEY_2, KEY_3, KEY_A },      \
           { KEY_4, KEY_5, KEY_6, KEY_B },      \
           { KEY_7, KEY_8, KEY_9, KEY_C },      \
           { KEY_STAR, KEY_0, KEY_HASH, KEY_D } \
        };
};

#endif
