#pragma once
#include <iostream>
#include "Insert.h"
#include "IllegalCharException.h"
using namespace std;


class Character {
    
    public:
   	
    char ch;
   
    friend ostream& operator<< (ostream& os, const Character& chara);
    friend bool operator== (const Character c1, const char c2);
   
    Character(char c);
    Character();
   
    void operator= (const Character chara);
	void operator= (char c);
    operator char();
};
