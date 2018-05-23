#pragma once
#include "Player.h"
#include "Board.h"

class TicTacToe {

    public:

    uint size;
    Board b{0};
    Player * won;

    TicTacToe (uint num){
        Board temp {num};
        size = num;
        b = temp;
    }

    void play(Player& xp, Player& op);
    const Board board() const;
    const Player& winner() const;


    bool goLine(char) const;
    bool goColumn(char) const;
    bool diagonal(char) const;
    bool isWin(const char) const;
    // void makingMove(char, Player& xp, Player& op);
};