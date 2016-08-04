#include "King.h"
#include "Board.h"

//private



//public

//ctr
King::King(bool isWhite):
    Piece(isWhite, 'K', Piece::KING, 1000000)
{

}

King::King(const King& king):
    Piece(king)
{

}

void King::calcValidMoves(const Board &board, Coord coord)
{
//    std::cout << "King\n";

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

    //castle (this is gross. hopefully it works...)
    if(isWhite() && !hasMoved() && coord.x == 4 && coord.y == 7) //white
    {
        const Piece* rr = board.getPiece(Coord(7,7));
        const Piece* lr = board.getPiece(Coord(0,7));

        if(rr && rr->getType() == Piece::ROOK && !rr->hasMoved())
        {
            crawler = coord;
            crawler.x++;
            if(!board.getPiece(crawler))
            {
                Board* b = new Board(board);
                b->move(coord, crawler);
                b->calcValidMoves(); 
                if(!b->isKingInCheck(isWhite()))
                {
                    crawler.x++;
                    if(!board.getPiece(crawler))
                    {
                        Board* c = new Board(*b);
                        Coord tmp = coord;
                        tmp.x++;
                        c->move(tmp, crawler);
                        c->calcValidMoves();
                        if(!c->isKingInCheck(isWhite()))
                        {
                            _validMoves.push_back(crawler);
                        }
                        c->deletePieceBoards();
                        delete c;
                    } 
                }
                b->deletePieceBoards();
                delete b;
            }
        } 
        if(lr && lr->getType() == Piece::ROOK && !lr->hasMoved())
        {
            crawler = coord;
            crawler.x--;
            if(!board.getPiece(crawler))
            {
                Board* b = new Board(board);
                b->move(coord, crawler);
                b->calcValidMoves(); 
                if(!b->isKingInCheck(isWhite()))
                {
                    crawler.x--;
                    if(!board.getPiece(crawler))
                    {
                        Board* c = new Board(*b);
                        Coord tmp = coord;
                        tmp.x--;
                        c->move(tmp, crawler);
                        c->calcValidMoves();
                        if(!c->isKingInCheck(isWhite()))
                        {
                            crawler.x--;
                            if(!board.getPiece(crawler))
                            {
                                _validMoves.push_back(crawler);
                            }
                        }
                        c->deletePieceBoards();
                        delete c;
                    } 
                }
                b->deletePieceBoards();
                delete b;
            }
        } 

    }
    else if(!hasMoved() && coord.x == 4 && coord.y == 0)//black
    {
        const Piece* rr = board.getPiece(Coord(7,0));
        const Piece* lr = board.getPiece(Coord(0,0));

        if(rr && rr->getType() == Piece::ROOK && !rr->hasMoved())
        {
            crawler = coord;
            crawler.x++;
            if(!board.getPiece(crawler))
            {
                Board* b = new Board(board);
                b->move(coord, crawler);
                b->calcValidMoves(); 
                if(!b->isKingInCheck(isWhite()))
                {
                    crawler.x++;
                    if(!board.getPiece(crawler))
                    {
                        Board* c = new Board(*b);
                        Coord tmp = coord;
                        tmp.x++;
                        c->move(tmp, crawler);
                        c->calcValidMoves();
                        if(!c->isKingInCheck(isWhite()))
                        {
                            _validMoves.push_back(crawler);
                        }
                        c->deletePieceBoards();
                        delete c;
                    } 
                }
                b->deletePieceBoards();
                delete b;
            }
        } 
        if(lr && lr->getType() == Piece::ROOK && !lr->hasMoved())
        {
            crawler = coord;
            crawler.x--;
            if(!board.getPiece(crawler))
            {
                Board* b = new Board(board);
                b->move(coord, crawler);
                b->calcValidMoves(); 
                if(!b->isKingInCheck(isWhite()))
                {
                    crawler.x--;
                    if(!board.getPiece(crawler))
                    {
                        Board* c = new Board(*b);
                        Coord tmp = coord;
                        tmp.x--;
                        c->move(tmp, crawler);
                        c->calcValidMoves();
                        if(!c->isKingInCheck(isWhite()))
                        {
                            crawler.x--;
                            if(!board.getPiece(crawler))
                            {
                                _validMoves.push_back(crawler);
                            }
                        }
                        c->deletePieceBoards();
                        delete c;
                    } 
                }
                b->deletePieceBoards();
                delete b;
            }
        } 
    }
}


Piece* King::clone() const
{
    return new King(*this);
}

void King::handleSpecialCase(Board& board, Coord src, Coord dest)
{
    if(dest.x - src.x == 2)
    {
        Coord rook = src;
        rook.x = 7;
        Coord tmp = dest;
        tmp.x--;
        board.setPiece(tmp, board.getPiece(rook));
        board.getPiece(rook)->setHasMoved(true);
        board.setPiece(rook, 0);
    }
    else if(dest.x - src.x == -2)
    {
        Coord rook = src;
        rook.x = 0;
        Coord tmp = dest;
        tmp.x++;
        board.setPiece(tmp, board.getPiece(rook));
        board.getPiece(rook)->setHasMoved(true);
        board.setPiece(rook, 0);
    }
}




