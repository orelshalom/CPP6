#include <iostream>
#include "Character.h"
using namespace std;


Character::Character(char c){
        ch = c;
}

Character::Character(){
        ch = '.';
}

ostream& operator<< (ostream& os, const Character& chara){
    return os << chara.ch;
}

void Character::operator= (const Character chara){
    ch = chara.ch;
}

void Character::operator= (char c){
    if(c != 'X' && c != 'O'){
        throw IllegalCharException(c);
    }
    ch = c;
}

bool operator== (const Character c1, const char c2){
    return c1.ch == c2;
}

Character::operator char(){
    return ch;
}