#include "Rook.h"

//private



//public

//ctr
Rook::Rook(bool isWhite):
    Piece(isWhite)
{

}

void Rook::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* Rook::clone() const
{
    return new Rook(*this);
}





