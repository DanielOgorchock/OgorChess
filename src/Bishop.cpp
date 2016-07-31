#include "Bishop.h"
#include "Board.h"

//private



//public

//ctr
Bishop::Bishop(bool isWhite):
    Piece(isWhite, 'B')
{

}

Bishop::Bishop(const Bishop& bishop):
    Piece(bishop.isWhite(), 'B')
{

}

void Bishop::calcValidMoves(const Board &board, Coord coord)
{
    std::cout << "Bishop\n";

    _validMoves.clear();
    Coord crawler;
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


Piece* Bishop::clone() const
{
    return new Bishop(*this);
}





