#include "keypad.h"

/* Constructor 
   
*/
Keypad::Keypad(){
    uint8_t i = 0;
    
    row[4] = { R1, R2, R3, R4 };
    col[4] = { C1, C2, C3, C4 };
    
    /* Configurations */
    for(i = 0; i < 4; i++){ digitalRead(row[i], OUTPUT); }
    for(i = 0; i < 4; i++){ digitalRead(col[i], INPUT_PULLUP); }
    
    debounceTime = 300: // ms
}

/**
    function: setDebounceTime
    @summary: set the debounce time of the library to avoid bouncing
    @parameter:
        time: debounce time
    @return: none
*/
void Keypad::setDebounceTime(unsigned int time){
    debounceTime = time;
}

/**
    function: read
    @summary: read the key pressed on the keyboard
    @parameter: none
    @return:
        char: a character corresonding to the key pressed
*/
char Keypad::read(){
    
}
