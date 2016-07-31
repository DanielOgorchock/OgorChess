#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    private:

    public:
        //ctr
        Pawn(bool isWhite);
        Pawn(const Pawn& pawn);

        virtual void calcValidMoves(const Board& board, Coord coord);

        virtual Piece* clone() const;

};


#endif
