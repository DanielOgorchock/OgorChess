#include "Piece.h"
#include "Board.h"

//private


//public

//ctr
Piece::Piece(bool isWhite, char charRep, Type type, float value):
    _isWhite(isWhite),
    _charRep(charRep),
    _type(type),
    _hasMoved(false),
    _value(value)
{

}
Piece::Piece(const Piece& piece):
    _isWhite(piece._isWhite),
    _charRep(piece._charRep),
    _type(piece._type),
    _hasMoved(piece._hasMoved),
    _value(piece._value)
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
        b->toggleTurn();
        if(!b->isKingInCheck(_isWhite))
        {
            _newBoards.push_back(std::make_pair(b, Move(coord, c)));
        }
        else
        {
            delete b;
        }
    } 
}

bool Piece::hasRefinedMove(Coord c)
{
    for(auto pair : _newBoards)
    {
        if(pair.second.dest == c)
        {
            return true;
        }
    }
    return false;
}

void Piece::handleSpecialCase(Board& board, Coord src, Coord dest)
{
    // many classes won't need to worry about this, so don't make them all implement it
}

void Piece::deleteBoards()
{
    for(auto b : _newBoards)
    {
        delete b.first;
    }
    _newBoards.clear();
}

