#include "Pawn.h"

//private



//public

//ctr
Pawn::Pawn(bool isWhite):
    Piece(isWhite, 'P')
{

}

void Pawn::calcValidMoves(const Board &board, Coord coord)
{

}


Piece* Pawn::clone() const
{
    return new Pawn(*this);
}




