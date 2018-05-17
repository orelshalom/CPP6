#pragma once
#include <iostream>
#include "Character.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
using namespace std;


class Board {
    
    friend ostream& operator<< (ostream& os, const Board& b);	

    public:

    Character ** matrix;
    uint boardSize;

    Board (uint extent) : boardSize(extent){
        matrix = new Character * [boardSize];
        for(int i = 0; i < boardSize; ++i)
            matrix[i] = new Character [boardSize];   
    }
    Board (const Board& b);
    ~Board();

    Character& operator[] (Coordinate coor) const;
    void operator= (const Board&);
	void operator= (char c);
    const uint size() const; 

};
