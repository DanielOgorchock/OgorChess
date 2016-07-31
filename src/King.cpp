#include "King.h"

//private



//public

//ctr
King::King(bool isWhite):
    Piece(isWhite, 'K')
{

}

void King::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* King::clone() const
{
    return new King(*this);
}




