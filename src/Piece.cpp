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
        std::cout<<"COPIED\n";
        b->move(coord, c);
        std::cout<<"MOVED\n";
        b->calcValidMoves();
        std::cout<<"CALCED\n";
        b->toggleTurn();
        std::cout<<"TOGGLED\n";
        if(!b->isKingInCheck(_isWhite))
        {
            _newBoards.push_back(b);
        }
        else
        {
            delete b;
        }
        std::cout<<"LOOP_DONE\n";
    } 
}

void Piece::handleSpecialCase(Board& board, Coord src, Coord dest)
{
    // many classes won't need to worry about this, so don't make them all implement it
}


