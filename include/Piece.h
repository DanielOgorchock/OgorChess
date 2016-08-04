#ifndef PIECE_H
#define PIECE_H
// This is an abstract class which provides a common interface for the various chess pieces
//
//

#include "Coord.h"
#include <vector>
#include <iostream>
#include <utility>

class Board;

class Piece
{
    public:
        enum Type{
            PAWN,
            ROOK,
            KNIGHT,
            BISHOP,
            QUEEN,
            KING
        };

    private:
        bool _isWhite;
        char _charRep;
        Type _type;
        bool _hasMoved;
        float _value;

    protected:
        // vector of valid coordinates to which this piece can move
        std::vector<Coord> _validMoves;

        // vector of new board states as a result of the valid moves
        // these boards should contain pieces which have all had
        // calculateValidMoves() run on them, but not yet
        // refineValidMoves()
        std::vector<std::pair<Board*, Move>> _newBoards;

    public:
        //ctr
        Piece(bool isWhite, char charRep, Type type, float value);
        Piece(const Piece& piece);

        //dtr
        virtual ~Piece();

        bool isWhite() const {return _isWhite;}
        
        void setIsWhite(bool b) {_isWhite = b;}

        char getCharRep() const {return _charRep;}

        Type getType() const {return _type;}

        float getValue() const {return _value;}

        bool hasMoved() const {return _hasMoved;}
        void setHasMoved(bool b) {_hasMoved = b;}

        const std::vector<Coord>& getValidMoves() const {return _validMoves;}

        const std::vector<std::pair<Board*, Move>>& getNewBoards() const {return _newBoards;}

        // This calculates the valid moves for this piece
        // Note: this method ignores the possiblity of putting own king in check
        //       refineValidMoves takes this into account
        virtual void calcValidMoves(const Board& board, Coord coord) = 0;

        // Second stage of valid moves calculation (considers putting self in check)
        void refineValidMoves(const Board& board, Coord coord);

        bool hasRefinedMove(Coord c);

        // Base implementation does nothing
        virtual void handleSpecialCase(Board& board, Coord src, Coord dest);

        virtual Piece* clone() const = 0;

        void deleteBoards();

};



#endif
