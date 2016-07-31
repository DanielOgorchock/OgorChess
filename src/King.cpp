#include "King.h"
#include "Board.h"

//private



//public

//ctr
King::King(bool isWhite):
    Piece(isWhite, 'K')
{

}

King::King(const King& king):
    Piece(king.isWhite(), 'K')
{

}

void King::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "King\n";

    _validMoves.clear();
    Coord crawler;

    //up-left
    crawler = coord;
    crawler.x--;
    crawler.y--;
    if(crawler.x>=0 && crawler.y>=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //up-right
    crawler = coord;
    crawler.x++;
    crawler.y--;
    if(crawler.x<=7 && crawler.y>=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //down-left
    crawler = coord;
    crawler.x--;
    crawler.y++;
    if(crawler.x>=0 && crawler.y<=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //down-right
    crawler = coord;
    crawler.x++;
    crawler.y++;
    if(crawler.x<=7 && crawler.y<=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //up
    crawler = coord;
    crawler.y--;
    if(crawler.y>=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //down
    crawler = coord;
    crawler.y++;
    if(crawler.y<=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //left
    crawler = coord;
    crawler.x--;
    if(crawler.x>=0)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

    //right
    crawler = coord;
    crawler.x++;
    if(crawler.x<=7)
    {
        const Piece* p = board.getPiece(crawler);
        if(!p || p->isWhite() != isWhite())
        {
            _validMoves.push_back(crawler);
        }
    }

}


Piece* King::clone() const
{
    return new King(*this);
}




