#ifndef BOARD_H
#define BOARD_H

// Class representing the chessboard

#include "Piece.h"
#include "Coord.h"
#include <vector>
#include <utility>

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
        std::vector<std::pair<Board*, Move>> _newBoards;
        unsigned long _drawCount = 0;

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

        unsigned long getDrawCount() const {return _drawCount;}

        void calcValidMoves();
        void refineValidMoves();
        
        void populateNewBoards();

        const std::vector<std::pair<Board*, Move>>& getNewBoards() const {return _newBoards;}
        std::vector<std::pair<Board*, Move>>& getNewBoards() {return _newBoards;}

        bool isKingInCheck(bool whiteKing);

};



#endif
