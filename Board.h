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

    Board (const Board& b);
    Board (int extent) : size(extent){
        matrix = new Character * [size];
        for(int i = 0; i < size; ++i)
            matrix[i] = new Character [size];
	}

    Character& operator[] (Insert in);
    void operator= (const Board& b);
	void operator= (char c);
};
