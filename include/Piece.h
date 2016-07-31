#ifndef PIECE_H
#define PIECE_H
// This is an abstract class which provides a common interface for the various chess pieces
//
//

#include "Coord.h"
#include <vector>

class Board;

class Piece
{
    private:
        bool _isWhite;
        char _charRep;

    protected:
        // vector of valid coordinates to which this piece can move
        std::vector<Coord> _validMoves;

        // vector of new board states as a result of the valid moves
        // these boards should contain pieces which have all had
        // calculateValidMoves() run on them, but not yet
        // refineValidMoves()
        std::vector<Board*> _newBoards;

    public:
        //ctr
        Piece(bool isWhite, char charRep);

        //dtr
        virtual ~Piece();

        bool isWhite() const {return _isWhite;}
        
        void setIsWhite(bool b) {_isWhite = b;}

        char getCharRep() const {return _charRep;}

        const std::vector<Coord>& getValidMoves() const {return _validMoves;}

        const std::vector<Board*>& getNewBoards() const {return _newBoards;}

        // This calculates the valid moves for this piece
        // Note: this method ignores the possiblity of putting own king in check
        //       refineValidMoves takes this into account
        virtual void calcValidMoves(const Board& board, Coord coord) = 0;

        // Second stage of valid moves calculation (considers putting self in check)
        void refineValidMoves(const Board& board, Coord coord);

        // Base implementation does nothing
        virtual void handleSpecialCase(Board& board, Coord src, Coord dest);

        virtual Piece* clone() const = 0;



};



#endif
