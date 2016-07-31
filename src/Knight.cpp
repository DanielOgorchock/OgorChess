#include "Knight.h"

//private



//public

//ctr
Knight::Knight(bool isWhite):
    Piece(isWhite)
{

}

void Knight::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* Knight::clone() const
{
    return new Knight(*this);
}





