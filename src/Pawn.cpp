#include "Pawn.h"
#include "Board.h"
#include "Queen.h"
#include <unistd.h>

//private



//public

//ctr
Pawn::Pawn(bool isWhite):
    Piece(isWhite, 'P', Piece::PAWN, 1)
{

}

Pawn::Pawn(const Pawn& pawn):
    Piece(pawn)
{

}

void Pawn::calcValidMoves(const Board &board, Coord coord)
{
//    std::cout << "Pawn\n";

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
    if(crawler.y>=0 && crawler.y<=7 && !board.getPiece(crawler))
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

    //en passant
    if(isWhite() && coord.y == 3
                && board.getPiece(board.getLastMoveDest())->getType() == Piece::PAWN
                && !board.getPiece(board.getLastMoveDest())->isWhite())
    {
        Coord src = coord;
        src.x--;
        src.y-=2;
        Coord dest = coord;
        dest.x--;
        if(src == board.getLastMoveSrc() && dest == board.getLastMoveDest())
        {
            crawler = coord;
            crawler.x--;
            crawler.y--;
            _validMoves.push_back(crawler);
        }

        src = coord;
        src.x++;
        src.y-=2;
        dest = coord;
        dest.x--;
        if(src == board.getLastMoveSrc() && dest == board.getLastMoveDest())
        {
            crawler = coord;
            crawler.x++;
            crawler.y--;
            _validMoves.push_back(crawler);
        }
    }
    else if (!isWhite() && coord.y == 4
                && board.getPiece(board.getLastMoveDest())->getType() == Piece::PAWN
                && board.getPiece(board.getLastMoveDest())->isWhite())
    {
        Coord src = coord;
        src.x--;
        src.y+=2;
        Coord dest = coord;
        dest.x--;
        if(src == board.getLastMoveSrc() && dest == board.getLastMoveDest())
        {
            crawler = coord;
            crawler.x--;
            crawler.y++;
            _validMoves.push_back(crawler);
        }

        src = coord;
        src.x++;
        src.y+=2;
        dest = coord;
        dest.x--;
        if(src == board.getLastMoveSrc() && dest == board.getLastMoveDest())
        {
            crawler = coord;
            crawler.x++;
            crawler.y++;
            _validMoves.push_back(crawler);
        }

    }
}


Piece* Pawn::clone() const
{
    return new Pawn(*this);
}


void Pawn::handleSpecialCase(Board& board, Coord src, Coord dest)
{
    if(isWhite() && dest.y == 0)
    {
        board.setPiece(dest, new Queen(true));
    }
    else if (dest.y == 7)
    {
        board.setPiece(dest, new Queen(false));
    }
}

