#pragma once
#include <string>
#include "Board.h"
#include "Character.h"

class Player {
    
    public:

    char myChar;

    virtual const string name() const { return "Some Player"; }
    virtual const Coordinate play(const Board& board) { return {0,0}; }
    
    char getChar() const;
    void setChar(char);

};