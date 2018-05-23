#include <iostream>
#include "TicTacToe.h"
using namespace std;


void TicTacToe::play(Player& xp, Player& op){
    xp.myChar = 'X';
    op.myChar = 'O';
    int num = size * size;
    int count = 0;
    int turn = 1;

	while (count < num){
        if(turn == 1){
            try {
                Coordinate place;
                place = xp.play(b);
                if (b[place] != '.') throw string("Illegal Player!");
                b[place] = xp.myChar;
                if(isWin(xp.myChar)){
                    won = &xp;
                    return;
                }
                turn = 2;
            }
            catch (...){
                won = &op;
                return;
            }
            count++;            
        }
        if (turn == 2 && count < num){
            try {
                Coordinate place;
                place = op.play(b);
                if (b[place] != '.') throw string("Illegal Player!");
                b[place] = op.myChar;
                if(isWin(op.myChar)){
                    won = &op;
                    return;
                }
                turn = 1;
            }
            catch (...){
                won = &xp;
                return;
            }
            count++;           
        }
	}
    won = &op;
}

const Board TicTacToe::board() const{
    return b;
}

const Player& TicTacToe::winner() const{
    b = '.';
    return * won;
}

bool TicTacToe::goLine(char player) const{
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){
            Coordinate c{i,j};
			if(b[c] == player) count++;
            else {
                count = 0;
                break;
            }
			if(count == size){
				return true;
			}
		}
	}
	return false;

}

bool TicTacToe::goColumn(char player) const{
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){ 
			Coordinate c{j,i};
            if(b[c] == player) count++;
            else {
                count = 0;
                break;
            }
            if(count == size){
				return true;
			}
		}
	}
	return false;
}

bool TicTacToe::diagonal(char player) const{
    uint count = 0;
    uint i = 0, j = 0;
    Coordinate c{i,j};
    
    if(b[c] == player){
        count++;
        while(i+1 <= size-1 && j+1 <= size-1 && b[{i+1,j+1}] == player && count < size){
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
        while(i+1 <= size-1 && t-1 >= 0 && b[{i+1,j-1}] == player && count < size){
            count++;
            i++;
            j--;
            t--;
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
