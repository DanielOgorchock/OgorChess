#include "Queen.h"
#include "Board.h"

//private



//public

//ctr
Queen::Queen(bool isWhite):
    Piece(isWhite, 'Q')
{

}

Queen::Queen(const Queen& queen):
    Piece(queen.isWhite(), 'Q')
{

}

void Queen::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "Queen\n";

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

    //up-left
    crawler = coord; 
    crawler.x--;
    crawler.y--;
    while(crawler.x >=0 && crawler.y >=0)
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
        crawler.y--;
    }

    //up-right
    crawler = coord; 
    crawler.x++;
    crawler.y--;
    while(crawler.x <=7 && crawler.y >=0)
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
        crawler.y--;
    }

    //down-left
    crawler = coord; 
    crawler.x--;
    crawler.y++;
    while(crawler.x >=0 && crawler.y <=7)
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
        crawler.y++;
    }

    //down-right
    crawler = coord; 
    crawler.x++;
    crawler.y++;
    while(crawler.x <=7 && crawler.y <=7)
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
        crawler.y--;
    }
}


Piece* Queen::clone() const
{
    return new Queen(*this);
}





