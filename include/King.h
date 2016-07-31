#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
    private:

    public:
        //ctr
        King(bool isWhite);

        virtual void calcValidMoves(const Board& board, Coord coord);

        virtual Piece* clone() const;

};


#endif

