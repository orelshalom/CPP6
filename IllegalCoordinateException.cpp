#include <iostream>
#include <exception>
#include "IllegalCoordinateException.h"
using namespace std;


IllegalCoordinateException::IllegalCoordinateException(const Coordinate& coor){
    ill = new Coordinate(coor);
}

IllegalCoordinateException::~IllegalCoordinateException(){
    delete ill;
}

string IllegalCoordinateException::theCoordinate() const{
    ostringstream os;
    os << ill->row << ", " << ill->column << endl;
    return os.str();
}