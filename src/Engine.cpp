#include "Engine.h"
#include <iostream>
#include <vector>


//private






//public

//ctr
Engine::Engine(bool isWhite):
    _isWhite(isWhite),
    _turn(1)
{
    _root = new Board();
    _root->setIsWhiteTurn(true);

}


void Engine::giveMove(Move move)
{
    if(_turn == 1)
    {
        _root->calcValidMoves();
        _root->refineValidMoves();
        _root->populateNewBoards();
    }

    Board* tmp = _root;
    Board* nextBoard;

    for(auto b : _root->getNewBoards())
    {
        if(b.second != move)
        {
            cleanBoards(b.first);
        }
        else
        {
           nextBoard = b.first; 
        }
    }

    _root = nextBoard;
    delete tmp; 

    _turn++;
}

Move Engine::yourMove()
{
    if(_turn <= 2) //if this is our first turn, this was never calculated
    {
        _root->calcValidMoves();
        _root->refineValidMoves();
        _root->calcValue();
        _root->populateNewBoards();
    }

    
    for(auto b : _root->getNewBoards())
    {
        genBoards(b.first, 3);
    }     
  
    //determine best move choice 
    Move move = _root->getNewBoards()[0].second;
    float max = (_isWhite*1 + !_isWhite*(-1)) * _root->getNewBoards()[0].first->getValue();

    for(auto pair : _root->getNewBoards())
    {
        Move m = pair.second;
        pair.first->calcValue();
        float value = (_isWhite*1 + !_isWhite*(-1)) * pair.first->getValue();
        if(value > max)
        {
            move = m;
            max = value;
        }
    }
    std::cout << "Value: " << max << std::endl << std::endl;

    _turn++;

    Board* tmp = _root;
    Board* nextBoard;
    for(auto b : _root->getNewBoards())
    {
        if(b.second != move)
        {
            cleanBoards(b.first);
        }
        else
        {
           nextBoard = b.first; 
        }
    }

    _root = nextBoard;
    delete tmp; 

    return move;
}





void genBoards(Board* node, int depth)
{
    if(depth == 0)
    {
        return;
    }

    if(node->getNewBoards().size() == 0)
    {
        node->refineValidMoves();
        node->calcValue(); 
        node->populateNewBoards();
    }

    for(auto b : node->getNewBoards())
    {
        genBoards(b.first, depth - 1);
    }
}


void cleanBoards(Board* node)
{
    if(node->getNewBoards().size() == 0)
    {
        node->deletePieceBoards();
        delete node;
        return;
    }


    for(auto b : node->getNewBoards())
    {
        cleanBoards(b.first);
    }

    delete node;
}




