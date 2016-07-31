#include "Rook.h"
#include "Board.h"

//private



//public

//ctr
Rook::Rook(bool isWhite):
    Piece(isWhite, 'R')
{

}

Rook::Rook(const Rook& rook):
    Piece(rook.isWhite(), 'R')
{

}

void Rook::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "Rook\n";

    _validMoves.clear();
    Coord crawler;

    //up
    crawler = coord;
    crawler.y--;
    while(crawler.y >= 0)
    {
        const Piece* p = board.getPiece(crawler);
        if(p)
        {
            if(p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
            break;
        }
        _validMoves.push_back(crawler);

        crawler.y--;
    }

    //down
    crawler = coord;
    crawler.y++;
    while(crawler.y <= 7)
    {
        const Piece* p = board.getPiece(crawler);
        if(p)
        {
            if(p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
            break;
        }
        _validMoves.push_back(crawler);

        crawler.y++;
    }

    //left
    crawler = coord;
    crawler.x--;
    while(crawler.x >= 0)
    {
        const Piece* p = board.getPiece(crawler);
        if(p)
        {
            if(p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
            break;
        }
        _validMoves.push_back(crawler);

        crawler.x--;
    }

    //right
    crawler = coord;
    crawler.x++;
    while(crawler.x <= 7)
    {
        const Piece* p = board.getPiece(crawler);
        if(p)
        {
            if(p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
            break;
        }
        _validMoves.push_back(crawler);

        crawler.x++;
    }

}


Piece* Rook::clone() const
{
    return new Rook(*this);
}





