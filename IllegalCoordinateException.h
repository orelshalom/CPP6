#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include "Coordinate.h"
using namespace std;

class IllegalCoordinateException : public exception {

    Coordinate * ill;

    public:

    IllegalCoordinateException(const Coordinate& coor);
    ~IllegalCoordinateException();
    string theCoordinate() const;

};