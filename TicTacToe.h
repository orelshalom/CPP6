#pragma once
#include "Player.h"
#include "Board.h"

class TicTacToe {

    public:

    Board b {0};
    Board temp{0};
    uint size;
    Player p1, p2;

    TicTacToe (uint size){
        b.boardSize = size;
        temp.boardSize = size;
    }

    void play(Player& xp, Player& op);
    Board& board();
    Player& winner();
    int goLine(char);
    int goColumn(char);
    int diagonal(char);
    int isWin(const char);

};