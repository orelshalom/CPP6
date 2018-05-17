#pragma once
#include <string>
#include "Board.h"
#include "Character.h"

class Player {
    
    public:

    Character myChar;

    virtual const string name() const;
    virtual const Coordinate play(const Board& board);
    
    char getChar(){ return myChar.ch; }

};