#include "Piece.h"
#include "Board.h"

//private


//public

//ctr
Piece::Piece(bool isWhite, char charRep):
    _isWhite(isWhite),
    _charRep(charRep)
{

}

//dtr
Piece::~Piece()
{

}

void Piece::refineValidMoves(const Board &board, Coord coord)
{
    _newBoards.clear();
    for(Coord c : _validMoves)
    {
        Board* b = new Board(board); 
        b->move(coord, c);
        b->calcValidMoves();
    } 
}

void Piece::handleSpecialCase(Board& board, Coord src, Coord dest)
{
    // many classes won't need to worry about this, so don't make them all implement it
}


