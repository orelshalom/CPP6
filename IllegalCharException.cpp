#include <iostream>
#include <exception>
#include "IllegalCharException.h"
using namespace std;


IllegalCharException::IllegalCharException(const char c){
    ill = c;
}

const char IllegalCharException::theChar() const{
    return ill;
}