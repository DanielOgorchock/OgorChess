#include <iostream>
#include <websocketpp/config/core.hpp>
#include <websocketpp/client.hpp>
#include "Board.h"
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef websocketpp::client<websocketpp::config::core> WsClient;

void drawBoard(const Board& board)
{
    bool ws = true;
    for(unsigned int i = 0; i < 8; ++i)
    {
        for(unsigned int j = 0; j < 8; ++j)
        {
            std::string square;
            const Piece* p = board.getPiece(Coord(j,i)); 
            if(!p)
            {
                square = std::string("\033[1;") + (ws?"47m":"40m") + "   " + "\033[0m";
            }
            else if(p->isWhite())
            {
                square = std::string("\033[1;35;") + (ws?"47m ":"40m ") + p->getCharRep() + " \033[0m";
            }
            else
            {
                square = std::string("\033[1;31;") + (ws?"47m ":"40m ") + p->getCharRep() + " \033[0m";
            }
            std::cout << square;
            ws = !ws;
        }

        std::cout << std::endl;
        ws = !ws;
    }
    std::cout << std::endl;
}

void randomGame()
{
    unsigned long long numMoves = 0;
    srand (time(NULL));

    Board* board = new Board();
    board->setIsWhiteTurn(true);
    board->calcValidMoves();

    while(true)
    {
        drawBoard(*board);
        //sleep(1);
        board->refineValidMoves();
        board->populateNewBoards();
        auto newboards = board->getNewBoards();

        if(newboards.size() == 0)
        {
            if(board->isKingInCheck(board->isWhiteTurn()))
            {
                std::cout << "CHECKMATE!\n";
            }
            else
            {
                std::cout << "STALEMATE!\n";
            }
            break;
        }

        if(board->getDrawCount() >= 50)
        {
            std::cout << "DRAW!\n";
            break;
        }

        unsigned int index = rand() % newboards.size();

        for(unsigned int i = 0; i < newboards.size(); ++i)
        {
            if(i != index)
            {
                delete newboards[i];
            }
        }

        Board* oldboard = board;
        board = newboards[index]; 
        
        delete oldboard;

        ++numMoves;
        std::cout << numMoves << std::endl << std::endl;
    }
}

int main(int argn, char *argc[])
{        
/*    std::cout<<"Welcome to OgorChess!\n";
    Board board;
    board.calcValidMoves();
    std::cout<<"Valid moves already calculated.\n";


    std::cout<<"ROOK: " << board.getPiece(Coord(0,0))->getValidMoves().size() << std::endl;
    std::cout<<"KNIGHT: " << board.getPiece(Coord(1,0))->getValidMoves().size() << std::endl;
    std::cout<<"BISHOP: " << board.getPiece(Coord(2,0))->getValidMoves().size() << std::endl;
    std::cout<<"QUEEN: " << board.getPiece(Coord(3,0))->getValidMoves().size() << std::endl;
    std::cout<<"KING: " << board.getPiece(Coord(4,0))->getValidMoves().size() << std::endl;
    std::cout<<"BISHOP: " << board.getPiece(Coord(5,0))->getValidMoves().size() << std::endl;
    std::cout<<"KNIGHT: " << board.getPiece(Coord(6,0))->getValidMoves().size() << std::endl;
    std::cout<<"ROOK: " << board.getPiece(Coord(7,0))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(0,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(1,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(2,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(3,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(4,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(5,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(6,1))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(7,1))->getValidMoves().size() << std::endl;

    std::cout<<"ROOK: " << board.getPiece(Coord(0,7))->getValidMoves().size() << std::endl;
    std::cout<<"KNIGHT: " << board.getPiece(Coord(1,7))->getValidMoves().size() << std::endl;
    std::cout<<"BISHOP: " << board.getPiece(Coord(2,7))->getValidMoves().size() << std::endl;
    std::cout<<"QUEEN: " << board.getPiece(Coord(3,7))->getValidMoves().size() << std::endl;
    std::cout<<"KING: " << board.getPiece(Coord(4,7))->getValidMoves().size() << std::endl;
    std::cout<<"BISHOP: " << board.getPiece(Coord(5,7))->getValidMoves().size() << std::endl;
    std::cout<<"KNIGHT: " << board.getPiece(Coord(6,7))->getValidMoves().size() << std::endl;
    std::cout<<"ROOK: " << board.getPiece(Coord(7,7))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(0,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(1,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(2,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(3,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(4,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(5,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(6,6))->getValidMoves().size() << std::endl;
    std::cout<<"PAWN: " << board.getPiece(Coord(7,6))->getValidMoves().size() << std::endl;

    drawBoard(board);

    board.refineValidMoves();

    for(unsigned int i = 0; i < 8; ++i)
    {
        for(unsigned int j = 0; j < 8; ++j)
        {
            const Piece* p = board.getPiece(Coord(j,i));
            if(p)
            {
                for(const Board* b : p->getNewBoards())
                {
                    drawBoard(*b);
                }
            }  
        }
    }
*/
    randomGame();

    return 0;
}
