#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include "Character.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
using namespace std;

static int num = 0;

struct RGB {
    
    uint8_t red, green, blue;
    
    public:
      RGB() {}
      RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board {
    
    friend istream& operator>> (istream& is, Board& b);		
    friend ostream& operator<< (ostream& os, const Board& b);	

    public:

    Character ** matrix;
    uint boardSize;

    Board();
    Board (uint extent) : boardSize(extent){
        matrix = new Character * [boardSize];
        for(int i = 0; i < boardSize; ++i)
            matrix[i] = new Character [boardSize];   
    }
    Board (const Board& b);
    ~Board();

    Character& operator[] (Coordinate coor) const;
    void operator= (const Board&);
	void operator= (char c) const;
    const uint size() const; 

    string draw(int n);

};