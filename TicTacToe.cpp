#include <iostream>
#include "TicTacToe.h"
using namespace std;

void TicTacToe::play(Player& xp, Player& op){
    xp.myChar = 'X';
    op.myChar = 'O';
    p1 = xp;
    p2 = op;
    int winner = 0;
    int turn = 1;
    int first = 0;

	while (winner == 0){
		if(turn == 1){
            if((isWin(op.myChar.ch) == 1) || (xp.play(this->b).row == 0 && xp.play(this->b).column == 0 && first != 0)){
                winner = 2;
                break;
            }
            else{
                b[xp.play(this->b)] = xp.myChar;
            }
			turn = 2;
            first = 1;
		}
		else{ 
			if(turn == 2){
                if((isWin(xp.myChar.ch) == 1) || (op.play(this->b).row == 0 && op.play(this->b).column == 0 && first != 1)){
                    first = 1;
                    winner = 1;
                    break;
                }
                else{
                    b[op.play(this->b)] = op.myChar;
                }
				turn = 1;
                first = 2;
			}
		}
	}
    temp = b;
}

Board& TicTacToe::board(){
    return temp;
}

Player& TicTacToe::winner(){
    int Xcount = 0, Ocount = 0;
    for(uint i = 0; i < size; i++){
        for(uint j = 0; j < size; j++){
            if(b[{i,j}] == p1.myChar) Xcount++;
            else Ocount++;
        }
    }
    if(Xcount == Ocount && Xcount == size/2 && Ocount == size/2 ) return p2; 
    else{
        if(isWin('X') == 1) return p1;
        else return p2;
    }
}

int TicTacToe::goLine(char player){
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){
            Coordinate c{i,j};
			if (b[c] == player){
				count++;
			}
			if(count == size){
				return 1;
			}
            if(j == size-1){
                count = 0;
            }
		}
	}
	return 0;

}

int TicTacToe::goColumn(char player){
    int count = 0;
	for(uint i = 0 ; i < size; i++){
		for(uint j = 0; j < size; j++){ 
			Coordinate c{j,i};
            if (b[c] == player){
				count++;
			}
			if(count == size){
				return 1;
			}
            if(j == size-1){
                count = 0;
            }
		}
	}
	return 0;
}

int TicTacToe::diagonal(char player){
    int count = 0;
    uint i = 0, j = 0;
    int t;
    Coordinate c{i,j};
    
    if(b[c] == player){
        count++;
        while(i+1 <= size-1 && j+1 <= size-1 && b[{i+1,j+1}] == player && count < size){
            count++;
            i++;
            j++;
        }
        if(count == size){
            return 1;
        }
        count = 0;
	}

    j = size-1;
    t = j;
    i = 0;
    Coordinate d{i,j};

    if(b[d] == player){
        count++;
        while(i+1 <= size-1 && t-1 >= 0 && b[{i+1,j-1}] == player && count < size){
            count++;
            i++;
            j++;
        }
        if(count == size){
            return 1;
        }
	}
	return 0;
}

int TicTacToe::isWin(const char c){
    if(goLine(c) == 1 || goColumn(c) == 1 || diagonal(c) == 1){
        return 1;
    }
    return 0;
}
