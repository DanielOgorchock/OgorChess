#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

//private

void Board::clearBoard()
{
    for(unsigned char i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; ++i)
    {
        _grid[i] = 0;
    }
}

//public

//ctrs
Board::Board()
{
    clearBoard();
    
    //setup the default board state
    //
    //black
    setPiece(Coord(0,0), new Rook(false));
    setPiece(Coord(1,0), new Knight(false));
    setPiece(Coord(2,0), new Bishop(false));
    setPiece(Coord(3,0), new Queen(false));
    setPiece(Coord(4,0), new King(false));
    setPiece(Coord(5,0), new Bishop(false));
    setPiece(Coord(6,0), new Knight(false));
    setPiece(Coord(7,0), new Rook(false));
    for(unsigned int i = 0; i < BOARD_WIDTH; ++i)
    {
        setPiece(Coord(i, 1), new Pawn(false));
    }
    //
    //white
    setPiece(Coord(0,7), new Rook(true));
    setPiece(Coord(1,7), new Knight(true));
    setPiece(Coord(2,7), new Bishop(true));
    setPiece(Coord(3,7), new Queen(true));
    setPiece(Coord(4,7), new King(true));
    setPiece(Coord(5,7), new Bishop(true));
    setPiece(Coord(6,7), new Knight(true));
    setPiece(Coord(7,7), new Rook(true));
    for(unsigned int i = 0; i < BOARD_WIDTH; ++i)
    {
        setPiece(Coord(i, 6), new Pawn(true));
    }

    //set pointers to the kings
    _whiteKing = getPiece(Coord(4, 7));
    _blackKing = getPiece(Coord(4, 0));
}

Board::Board(const Board& board)
{
    clearBoard(); 

    for(unsigned int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; ++i)
    {
        const Piece* p = board._grid[i];
        if(!p && p!=board._whiteKing && p!=board._blackKing)
        {
            _grid[i]=p->clone();
        }
    }
    _whiteKing = board._whiteKing->clone();
    _blackKing = board._blackKing->clone();
}

//dtr
Board::~Board()
{
    for(unsigned int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; ++i)
    {
        if(_grid[i])
        {
            delete _grid[i];
        }
    }
}

void Board::move(Coord src, Coord dest)
{
    setPiece(dest, getPiece(src));
    setPiece(src, 0);
    _lastMoveSrc  = src;
    _lastMoveDest = dest;
    getPiece(dest)->handleSpecialCase(*this, src, dest);
}

void Board::calcValidMoves()
{
    for(unsigned int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; ++i)
    {
        if(_grid[i])
        {
            _grid[i]->calcValidMoves(*this, Coord(i%BOARD_WIDTH, i/BOARD_WIDTH));
        }
    } 
}

void Board::refineValidMoves()
{
    for(unsigned int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; ++i)
    {
        if(_grid[i])
        {
            _grid[i]->refineValidMoves(*this, Coord(i%BOARD_WIDTH, i/BOARD_WIDTH));
        }
    }
}




