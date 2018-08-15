/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 15/08/2018
    @version: 1.0
*/

#include "Keypad.h"

/* Constructor 
   
*/

Keypad::Keypad() { }

Keypad::~Keypad() {  }

void Keypad::begin() {
    uint8_t i = 0;
    /* Configurations */
    for(i = 0; i < 4; i++){ 
        pinMode(row[i], OUTPUT);
        digitalWrite(row[i], HIGH);
    }
    for(i = 0; i < 4; i++){ pinMode(col[i], INPUT_PULLUP); }
    
    debounceTime = 300; // ms
}

/**
    function: setDebounceTime
    @summary: set the debounce time of the library to avoid bouncing
    @parameter:
        time: debounce time
    @return: none
*/
void Keypad::setDebounceTime(unsigned int time) {
    debounceTime = time;
}

/**
    function: read
    @summary: read the key pressed on the keyboard
    @parameter: none
    @return:
        char: a character corresonding to the key pressed
*/
char Keypad::read() {
    uint8_t i = 0;
    uint8_t j = 0;
    
    for(i = 0; i < ROW_SIZE; i++){
        digitalWrite(row[i], LOW);
        for(j = 0; j < COL_SIZE; j++){
            if(!digitalRead(col[j])){
                delay(debounceTime);
                digitalWrite(row[i], HIGH);
                return pad[i][j];
            }
        }
        digitalWrite(row[i], HIGH);
    }
    return NONE;    
}

/**
    function: readPassword
    @summary: read a password from the key board
    @parameter:
        start: character that start the password recording
        end: character that end the password recording
    @return:
        String: password recorded
*/
String Keypad::readPassword(char start = '*', char end = '#', unsigned int timeout = 15000){
    String password = "";
    unsigned int _t = 0; // timeout counter
    char key = '-';
    while((key != start) || (key == NONE)){ 
        key = read();
        _t++; 
        if(_t >= timeout){ return "None"; }
    }
    _t = 0;
    key = read();
    while((key != end) || (key == NONE)){
        key = read();
        if((key != NONE) && (key != end)){ password += key; _t = 0; }
        _t++;
        if(_t >= timeout){ return "None"; }
    }
    return password;
}
