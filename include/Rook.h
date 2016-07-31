#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    private:

    public:
        //ctr
        Rook(bool isWhite);
        Rook(const Rook& rook);

        virtual void calcValidMoves(const Board& board, Coord coord);

        virtual Piece* clone() const;

};


#endif

