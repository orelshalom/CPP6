#include <iostream>
#include "Board.h"
using namespace std;


Board::Board (const Board& b){
    boardSize = b.boardSize;
    matrix = new Character * [boardSize];
    for(uint i = 0; i < boardSize; ++i){
        matrix[i] = new Character [boardSize]; 
        for(uint j = 0; j < boardSize; ++j)
            matrix[i][j] = b.matrix[i][j];
    }
}

Board::~Board(){
    for(uint i = 0; i < boardSize; ++i)
        delete[] matrix[i];
    delete[] matrix; 
}

ostream& operator<< (ostream& os, const Board& b){
    for(uint i = 0; i < b.boardSize; ++i){
        for(uint j = 0; j < b.boardSize; ++j){
            os << b.matrix[i][j];
            if(j == (b.boardSize - 1)) os << endl;
        }
    }
    return os;
}

Character& Board::operator[] (Coordinate coor) const{
    if(coor.row >= boardSize || coor.column >= boardSize) //coor.row < 0 || coor.column < 0 
        throw IllegalCoordinateException(coor);
    return matrix[coor.row][coor.column];
}

void Board::operator= (const Board& b){
    this->~Board();
    boardSize = b.boardSize;
    matrix = new Character * [boardSize];
    for(uint i = 0; i < boardSize; ++i){
        matrix[i] = new Character [boardSize]; 
        for(uint j = 0; j < boardSize; ++j)
            matrix[i][j] = b.matrix[i][j];
    }
}

void Board::operator= (char c) const{
    if(c == '.'){
        for(uint i = 0; i < boardSize; ++i){
            for(uint j = 0; j < boardSize; ++j)
                matrix[i][j].ch = '.';
        }
    } 
    else throw IllegalCharException(c);
}

const uint Board::size() const{
    return boardSize;
}