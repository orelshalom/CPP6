#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::~TicTacToe(){
    delete[] &b;
    delete[] won;
}

void TicTacToe::play(Player& xp, Player& op){
    xp.myChar = 'X';
    op.myChar = 'O';
    int num = size * size;
    int count = 0;
    
	while (count < num){
        if(won != &op && won != &xp) makingMove(xp.myChar, xp, op);
        if(isWin('X') || won == &xp){
            won = &xp;
            return;
        }

        if(won == &op) return;
        count++;
        
        if(won != &xp && count < num) makingMove(op.myChar, xp, op);
        
        if(isWin('O') || won == &op){
            won = &op;
            return;
        }

        if(won == &xp) return;
        count++;
	}
    if(won != &op || won != &xp) won = &op;
}

const Board TicTacToe::board() const{
    return b;
}

const Player& TicTacToe::winner() const{
    b = '.';
    return *won;
}

bool TicTacToe::goLine(const char player) const{
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){
            Coordinate c{i,j};
			if(b[c] == player) count++;
            else {
                count = 0;
                j = size;
            }
			if(count == size){
				return true;
			}
		}
	}
	return false;

}

bool TicTacToe::goColumn(const char player) const{
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){ 
			Coordinate c{j,i};
            if(b[c] == player) count++;
            else {
                count = 0;
                j = size;
            }
            if(count == size){
				return true;
			}
		}
	}
	return false;
}

bool TicTacToe::diagonal(const char player) const{
    int count = 0;
    uint i = 0, j = 0;
    Coordinate c{i,j};
    
    if(b[c] == player){
        count++;
        while(i+1 <= size-1 && j+1 <= size-1 && b[{i+1,j+1}] == player){
            count++;
            i++;
            j++;
        }
        if(count == size) return true;
	}
    
    count = 0;
    j = size-1;
    int t = size-1;
    i = 0;
    Coordinate d{i,j};

    if(b[d] == player){
        count++;
        while(i+1 <= size-1 && t-1 >= 0 && b[{i+1,j-1}] == player){
            count++;
            i++;
            j--;
        }
        if(count == size) return true;
	}
	return false;
}

bool TicTacToe::isWin(const char c) const {
    if(goLine(c) || goColumn(c) || diagonal(c)){
        return true;
    }
    return false;
}

void TicTacToe::makingMove(char c, Player& xp, Player& op){
    try {
        Coordinate place;
        c == 'X' ? place = xp.play(b) : place = op.play(b);
        if (b[place] != '.') throw string("Illegal Player!");
        b[place] = c;
    }
    catch (...){
        c == 'X' ? won = &op : won = &xp;
    }
}