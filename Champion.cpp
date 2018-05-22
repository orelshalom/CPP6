#include "Champion.h"

const Coordinate Champion::play(const Board& board){
    uint j = board.boardSize -1, i = 0;
    Coordinate c{i,j};
    if(board[c] == '.') return c;
    else{
        i = board.boardSize -1;
        j = 0;
        while(j <= board.boardSize-1){
            c.row = i;
            c.column = j;
            i--;
            j++;
            if(board[c] == '.') return c;
        }
    }
    return {0,0};
}
