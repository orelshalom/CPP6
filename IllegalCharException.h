#pragma once
#include <iostream>
#include <exception>
using namespace std;

class IllegalCharException : public exception {

    char ill;

    public:

    IllegalCharException(const char);
    const char theChar() const;

};