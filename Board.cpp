#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(){
    boardSize = 0;
    matrix = NULL;
}

Board::Board (const Board& b){
    boardSize = b.boardSize;
    matrix = new Character * [boardSize];
    for(uint i = 0; i < boardSize; ++i){
        matrix[i] = new Character [boardSize]; 
        for(uint j = 0; j < boardSize; ++j)
            matrix[i][j] = b.matrix[i][j];
    }
}

Board::~Board(){
    for(uint i = 0; i < boardSize; ++i)
        delete[] matrix[i];
    delete[] matrix; 
}

ostream& operator<< (ostream& os, const Board& b){
    for(uint i = 0; i < b.boardSize; ++i){
        for(uint j = 0; j < b.boardSize; ++j){
            os << b.matrix[i][j];
            if(j == (b.boardSize - 1)) os << endl;
        }
    }
    return os;
}

istream& operator>> (istream& is, Board& b){
	string line;
	is >> line;
    uint count = 0;
    
    while (count < line.length()){
        if(count ==  0){
            Board temp{(uint)line.length()};
            b = temp;
        }
        for(uint i = 0; i < line.length(); i++){
            b.matrix[count][i] = line[i];
        }
        count++;
    	is >> line;
    }
	return is;
}

Character& Board::operator[] (Coordinate coor) const{
    if(coor.row >= boardSize || coor.column >= boardSize) //coor.row < 0 || coor.column < 0 
        throw IllegalCoordinateException(coor);
    return matrix[coor.row][coor.column];
}

void Board::operator= (const Board& b){
    this->~Board();
    boardSize = b.boardSize;
    matrix = new Character * [boardSize];
    for(uint i = 0; i < boardSize; ++i){
        matrix[i] = new Character [boardSize]; 
        for(uint j = 0; j < boardSize; ++j)
            matrix[i][j] = b.matrix[i][j];
    }
}

void Board::operator= (char c) const{
    if(c == '.'){
        for(uint i = 0; i < boardSize; ++i){
            for(uint j = 0; j < boardSize; ++j)
                matrix[i][j].ch = '.';
        }
    } 
    else throw IllegalCharException(c);
}

const uint Board::size() const{
    return boardSize;
}

string Board::draw(int n){
    num++;
    while(true){
        ifstream f("d"+to_string(num)+".ppm");
        if(!f.good()) break;
        else num++;
    }
    
    string intstr = to_string(num);
    string name = "d" + intstr + ".ppm";
    ofstream imageFile(name, ios::out | ios::binary);
    imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
    RGB image[n*n];
    int cell = (n-(boardSize+1))/boardSize;
    
    for (int j = 0; j < n; ++j)  {  
        for (int i = 0; i < n; ++i) { 
            image[n*j+i].red = (217);
            image[n*j+i].green = (147);
            image[n*j+i].blue = (142);
            if((i%cell == 0 || j%cell == 0)){
                image[n*j+i].red = (0);
                image[n*j+i].green = (0);
                image[n*j+i].blue = (0);
            }
        }
    }

    int radius = (cell/2)-5;
    for(uint i = 0; i < boardSize; ++i){  
        for(uint j = 0; j < boardSize; ++j){ 
            if(matrix[i][j] == 'X'){
                int row = i*cell+1;
                int col = j*cell+1;
                int m = col;
                for(int k = row; k < row+cell; ++k){
                    m++;
                    image[n*k+m].red = (0);
                    image[n*k+m].green = (0);
                    image[n*k+m].blue = (0);
                }
                row += cell;
                m = col;
                for(int k = row; k > row-cell; --k){
                    m++;
                    image[n*k+m].red = (0);
                    image[n*k+m].green = (0);
                    image[n*k+m].blue = (0);
                }
            }
            if(matrix[i][j] == 'O'){
                int row = i*cell+1;
                int col = j*cell+1;
                int Xcenter = row+(cell/2);
                int Ycenter = col+(cell/2);
                for(int m = row; m < cell+row; ++m){  
                    for(int t = col; t < cell+col; ++t){
                        int dis = sqrt(pow(m-Xcenter,2) + pow(t-Ycenter,2));
                        if(dis == radius){
                            image[n*m+t].red = (0);
                            image[n*m+t].green = (0);
                            image[n*m+t].blue = (0); 
                        }
                    }
                }
            }
        }
    }
  
    imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
    imageFile.close();
    return name;
}