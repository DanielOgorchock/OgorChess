#include <iostream>
#include <websocketpp/config/core.hpp>
#include <websocketpp/client.hpp>


typedef websocketpp::client<websocketpp::config::core> WsClient;


int main(int argn, char *argc[])
{        
    std::cout<<"Welcome to OgorChess!\n";

    return 0;
}
