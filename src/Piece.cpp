#include "Piece.h"
#include "Board.h"

//private


//public

//ctr
Piece::Piece(bool isWhite):
    _isWhite(isWhite)
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




