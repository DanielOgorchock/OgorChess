#include "Coord.h"

//private


//public

//ctrs
Coord::Coord():
    x(0),
    y(0)
{

}

Coord::Coord(short X, short Y):
    x(X),
    y(Y)
{

}


bool operator==(Coord x, Coord y)
{
    return x.x == y.x && x.y == y.y;
}


