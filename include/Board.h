#ifndef BOARD_H
#define BOARD_H

// Class representing the chessboard

#include "Piece.h"
#include "Coord.h"

class Board
{
    private:
        static const unsigned char BOARD_WIDTH  = 8;
        static const unsigned char BOARD_HEIGHT = 8;

        Piece* _grid[BOARD_WIDTH * BOARD_HEIGHT];
        Piece* _whiteKing;
        Piece* _blackKing;
        Coord _lastMoveSrc;
        Coord _lastMoveDest;
        bool _whiteTurn;

        void clearBoard();

    public:
        //ctrs
        Board();
        Board(const Board& board); 

        //dtr
        ~Board();

        bool isWhiteTurn() const {return _whiteTurn;}
        void setIsWhiteTurn(bool b) {_whiteTurn = b;}
        void toggleTurn() {_whiteTurn = !_whiteTurn;}

        const Piece* getPiece(Coord c) const {return _grid[c.y*BOARD_WIDTH + c.x];}
        Piece* getPiece(Coord c) {return _grid[c.y*BOARD_WIDTH + c.x];}             
        
        void setPiece(Coord c, Piece* p) { _grid[c.y*BOARD_WIDTH + c.x] = p;}

        void move(Coord src, Coord dest);

        const Coord& getLastMoveSrc() const {return _lastMoveSrc;}
        const Coord& getLastMoveDest() const {return _lastMoveDest;}

        void calcValidMoves();
        void refineValidMoves();

        bool isKingInCheck(bool whiteKing);
};



#endif
