#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include "Insert.h"
using namespace std;

class IllegalCoordinateException : public exception {

    Insert * ill;

    public:

    IllegalCoordinateException(const Insert& in);
    string theCoordinate() const;

};