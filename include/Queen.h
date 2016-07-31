#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
    private:

    public:
        //ctr
        Queen(bool isWhite);
        Queen(const Queen& queen);

        virtual void calcValidMoves(const Board& board, Coord coord);

        virtual Piece* clone() const;

};


#endif

