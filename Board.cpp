#include <iostream>
#include "Board.h"
using namespace std;



Board::Board (const Board& b){
    size = b.size;
    matrix = new Character * [size];
    for(int i = 0; i < size; ++i)
        matrix[i] = new Character [size];   
}

void Board::freeBoard(){
    for(int i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;    
}

Board::~Board(){
    freeBoard();
}

ostream& operator<< (ostream& os, const Board& b){
    for(int i = 0; i < b.size; ++i){
        for(int j = 0; j < b.size; ++j){
            os << b.matrix[i][j];
            if(j == (b.size-1)) os << endl;
        }
    }
    return os;
}

Character& Board::operator[] (Insert in){
    if(in.row < 0 || in.column < 0 || in.row >= size || in.column >= size)
        throw IllegalCoordinateException(in);
    return matrix[in.row][in.column];
}

void Board::operator= (const Board& b){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            matrix[i][j] = b.matrix[i][j];
        }
    }
}

void Board::operator= (char c){
    if(c == '.'){
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j)
                matrix[i][j].ch = '.';
        }
    } 
    else throw IllegalCharException(c);
}
