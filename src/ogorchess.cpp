#include <iostream>
#include <websocketpp/config/core.hpp>
#include <websocketpp/client.hpp>
#include "Board.h"
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <Engine.h>

typedef websocketpp::client<websocketpp::config::core> WsClient;

void drawBoard(const Board& board)
{
    bool ws = true;
    for(unsigned int i = 0; i < 8; ++i)
    {
        std::cout << i << " ";
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
    std::cout << "   0  1  2  3  4  5  6  7";
    std::cout << std::endl << std::endl;
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
                delete newboards[i].first;
            }
        }

        Board* oldboard = board;
        board = newboards[index].first; 
        
        delete oldboard;

        ++numMoves;
        std::cout << numMoves << std::endl << std::endl;
    }
}

void localGame()
{
//    bool playerWhite = true;

    srand (time(NULL));

    Board* board = new Board();
    board->setIsWhiteTurn(true);
    board->calcValidMoves();

    while(true)
    {
        drawBoard(*board);

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


        Coord playerSrc, playerDest;
        std::cout << "Source x: ";
        std::cin >> playerSrc.x;
        std::cout << "Source y: ";
        std::cin >> playerSrc.y;
        std::cout << "Destination x: ";
        std::cin >> playerDest.x;
        std::cout << "Destination y: ";
        std::cin >> playerDest.y;

        bool validMove = false;
        for(auto pair : newboards)
        {
            if(pair.second.src == playerSrc && pair.second.dest == playerDest)
            {
                validMove = true;
                board = pair.first; 
                break;
            }
        }
        if(!validMove)
        {
            std::cout << "Invalid Move. YOU LOSE!\n";
            break;
        }

        drawBoard(*board);
        board->refineValidMoves();
        board->populateNewBoards();
        newboards = board->getNewBoards();

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

        board = newboards[index].first; 
    }
}

bool isGameOver(const Board* board)
{
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
        return true;
    }

    if(board->getDrawCount() >= 50)
    {
        std::cout << "DRAW!\n";
        return true;
    }
    return false;
}

void playSelf()
{
    Engine white(true);
    Engine black(false);
    int num = 0;

    while(true)
    {
        black.giveMove(white.yourMove());
        drawBoard(*white.getCurrentBoard());
        std::cout << ++num << std::endl << std::endl;

        if(isGameOver(white.getCurrentBoard()))
        {
            break;
        }

        white.giveMove(black.yourMove());
        drawBoard(*black.getCurrentBoard());
        std::cout << ++num << std::endl << std::endl;

        if(isGameOver(white.getCurrentBoard()))
        {
            break;
        }
    }
}

int main(int argn, char *argc[])
{        
    //randomGame();
    //localGame();
    playSelf();

    return 0;
}
