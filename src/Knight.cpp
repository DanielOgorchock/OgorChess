#include "Knight.h"
#include "Board.h"

//private



//public

//ctr
Knight::Knight(bool isWhite):
    Piece(isWhite, 'N')
{

}

Knight::Knight(const Knight& knight):
    Piece(knight.isWhite(), 'N')
{

}

void Knight::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "Knight\n";

    _validMoves.clear();

    Coord crawler;

    crawler = coord;
    crawler.x -= 2;
    crawler.y -= 1;
    if(crawler.x >=0 && crawler.y >=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x -= 1;
    crawler.y -= 2;
    if(crawler.x >=0 && crawler.y >=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x += 2;
    crawler.y += 1;
    if(crawler.x <=7 && crawler.y <=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x += 1;
    crawler.y += 2;
    if(crawler.x <=7 && crawler.y <=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x -= 2;
    crawler.y += 1;
    if(crawler.x >=0 && crawler.y <=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x -= 1;
    crawler.y += 2;
    if(crawler.x >=0 && crawler.y <=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x += 2;
    crawler.y -= 1;
    if(crawler.x <=7 && crawler.y >=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    crawler = coord;
    crawler.x += 1;
    crawler.y -= 2;
    if(crawler.x <=7 && crawler.y >=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

}


Piece* Knight::clone() const
{
    return new Knight(*this);
}





