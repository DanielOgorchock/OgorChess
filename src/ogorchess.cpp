#include <iostream>
#include <websocketpp/config/core.hpp>
#include <websocketpp/client.hpp>
#include "Board.h"

typedef websocketpp::client<websocketpp::config::core> WsClient;


int main(int argn, char *argc[])
{        
    std::cout<<"Welcome to OgorChess!\n";
    Board board;
    board.calcValidMoves();
    board.refineValidMoves();

    return 0;
}
