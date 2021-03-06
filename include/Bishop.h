#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    private:

    public:
        //ctr
        Bishop(bool isWhite);
        Bishop(const Bishop& bishop);

        virtual void calcValidMoves(const Board& board, Coord coord);

        virtual Piece* clone() const;

};


#endif

