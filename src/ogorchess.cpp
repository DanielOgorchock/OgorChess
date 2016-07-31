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

    board.refineValidMoves();

    return 0;
}
