#ifndef BOARD_H
#define BOARD_H

// Class representing the chessboard

#include "Piece.h"

class Board
{
    private:
        static const unsigned char BOARD_WIDTH  = 8;
        static const unsigned char BOARD_HEIGHT = 8;

        Piece* _grid[BOARD_WIDTH * BOARD_HEIGHT];
        Piece* _whiteKing;
        Piece* _blackKing;

        void clearBoard();

    public:
        //ctrs
        Board();
        Board(const Board& board); 

        //dtr
        ~Board();

        const Piece* getPiece(Coord c) const {return _grid[c.y*BOARD_WIDTH + c.x];}
        Piece* getPiece(Coord c) {return _grid[c.y*BOARD_WIDTH + c.x];}             
        
        void setPiece(Coord c, Piece* p) { _grid[c.y*BOARD_WIDTH + c.x] = p;}

        void move(Coord src, Coord dest);

        void calcValidMoves();
};



#endif
