#include "Bishop.h"

//private



//public

//ctr
Bishop::Bishop(bool isWhite):
    Piece(isWhite, 'B')
{

}

void Bishop::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* Bishop::clone() const
{
    return new Bishop(*this);
}





