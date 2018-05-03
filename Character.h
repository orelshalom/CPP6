#pragma once
#include <iostream>
#include "Insert.h"
#include "IllegalCharException.h"
using namespace std;


class Character {
    
    public:
   	
    char ch;
    friend ostream& operator<< (ostream& os, const Character& chara);
    Character(char c);
    Character();
    void operator= (const Character chara);
	void operator= (char c);

};
