#include "Queen.h"

//private



//public

//ctr
Queen::Queen(bool isWhite):
    Piece(isWhite)
{

}

void Queen::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* Queen::clone() const
{
    return new Queen(*this);
}





