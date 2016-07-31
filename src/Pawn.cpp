#include "Pawn.h"
#include "Board.h"

//private



//public

//ctr
Pawn::Pawn(bool isWhite):
    Piece(isWhite, 'P')
{

}

Pawn::Pawn(const Pawn& pawn):
    Piece(pawn.isWhite(), 'P')
{

}

void Pawn::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "Pawn\n";

    _validMoves.clear();

    Coord crawler;

    // move one square forward
    crawler = coord;
    if(isWhite())
    {
        crawler.y--;
    }
    else
    {
        crawler.y++;
    }
    if(!board.getPiece(crawler))
    {
        _validMoves.push_back(crawler);
    }

    // move two forward
    crawler = coord;
    if(isWhite() && crawler.y==6)
    {
        crawler.y-=2;
        const Piece* p = board.getPiece(crawler);
        if(!p)
        {
            _validMoves.push_back(crawler);
        }
    }
    else if(!isWhite() && crawler.y==1)
    {
        crawler.y+=2;
        const Piece* p = board.getPiece(crawler);
        if(!p)
        {
            _validMoves.push_back(crawler);
        }
    }

    // diagonal
    if(isWhite())
    {
        crawler = coord;
        crawler.x--;
        crawler.y--;
        if(crawler.x >= 0 && crawler.y >= 0)
        {
            const Piece* p = board.getPiece(crawler);
            if(p && p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
        }
        
        crawler = coord;
        crawler.x++;
        crawler.y--;
        if(crawler.x <= 7 && crawler.y >= 0)
        {
            const Piece* p = board.getPiece(crawler);
            if(p && p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
        }
    }
    else
    {
        crawler = coord;
        crawler.x--;
        crawler.y++;
        if(crawler.x >= 0 && crawler.y <= 7)
        {
            const Piece* p = board.getPiece(crawler);
            if(p && p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
        }
        
        crawler = coord;
        crawler.x++;
        crawler.y++;
        if(crawler.x <= 7 && crawler.y <= 7)
        {
            const Piece* p = board.getPiece(crawler);
            if(p && p->isWhite() != isWhite())
            {
                _validMoves.push_back(crawler);
            }
        }

    }
}


Piece* Pawn::clone() const
{
    return new Pawn(*this);
}




