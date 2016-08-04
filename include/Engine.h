#ifndef ENGINE_H
#define ENGINE_H

#include "Board.h"
#include "Coord.h"

class Engine
{
    private:
        Board* _root;

        bool _isWhite;
        unsigned int _turn;

    public:
        //ctr
        Engine(bool isWhite);

        void giveMove(Move move);
        Move yourMove(); //the engine will make its move and return it to the caller
        

        bool isWhite() const {return _isWhite;}
        const Board* const getCurrentBoard() {return _root;}


};

    void genBoards(Board* node, int depth);
    void cleanBoards(Board* node);

#endif
