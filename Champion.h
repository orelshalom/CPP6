#pragma once
#include "Player.h"

class Champion : public Player {

    char myChar;
    const string name() const override { return "Orel Shalom & Naama Shtauber"; }
	const Coordinate play(const Board& board) override;
    char getChar() const;
    
};