#include "Board.h"
#include <iostream>

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

istream& operator>> (istream& is, Board& b){
	string path, line;
	is >> path;
	ifstream boardFile(path);
    uint count = 0;
    if (boardFile.is_open()){
        while (getline(boardFile, line)){
            if(count == 0) b.matrix = new Character * [line.length()];
            for(uint i = 0; i < line.length(); i++){
                b.matrix[i] = new Character [line.length()];
                b.matrix[count][i] = line[i];
                cout << b.matrix[count][i] ;
            }
            cout << endl;
            count++;
        }
        boardFile.close();
    }
    else cout << "Unable to open file"; 
    
	return is;
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