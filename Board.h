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
    int size; 

    Board (int extent) : size(extent){
        matrix = new Character * [size];
        for(int i = 0; i < size; ++i)
            matrix[i] = new Character [size];   
    }
    Board (const Board& b);
    void freeBoard();
    ~Board();

    Character& operator[] (Insert in);
    void operator= (const Board&);
	void operator= (char c);
};
