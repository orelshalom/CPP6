#include <iostream>
#include <exception>
#include "IllegalCoordinateException.h"
using namespace std;


IllegalCoordinateException::IllegalCoordinateException(const Insert& in){
    ill = new Insert(in);
}

IllegalCoordinateException::~IllegalCoordinateException(){
    delete pair;
}

string IllegalCoordinateException::theCoordinate() const{
    ostringstream os;
    os << ill->row << ", " << ill->column << endl;
    return os.str();
}