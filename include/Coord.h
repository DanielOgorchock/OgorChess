#ifndef COORD_H
#define COORD_H
// An incredibly simple class that represents a position on the board
// (the top left from white's perspective is the origin [0,0])


class Coord
{
    public:
        //ctrs
        Coord();
        Coord(short X, short Y);

        // the locations can be publically available
        short x = 0;
        short y = 0;

        friend bool operator==(Coord x, Coord y);
        friend bool operator!=(Coord x, Coord y);
};

struct Move
{
    Coord src;
    Coord dest;

    Move(Coord s, Coord d):
        src(s),
        dest(d)
    {

    }


    friend bool operator==(Move x, Move y);
    friend bool operator!=(Move x, Move y);
};

#endif
