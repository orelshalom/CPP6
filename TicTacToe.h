#pragma once
#include "Player.h"
#include "Board.h"

class TicTacToe {

    public:

    uint size;
    Board b{0};
    Player * won;

    TicTacToe (uint size){
        Board temp {size};
        b = temp;
    }

    void play(Player& xp, Player& op);
    Board board()const;
    Player& winner() const;


    bool goLine(char) const;
    bool goColumn(char) const;
    bool diagonal(char) const;
    bool isWin(const char) const;
    void doTurn(char, Player& xp, Player& op);
};