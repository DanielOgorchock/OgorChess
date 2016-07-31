#ifndef COORD_H
#define COORD_H
// An incredibly simple class that represents a position on the board
// (the top left from white's perspective is the origin [0,0])


class Coord
{
    public:
        //ctr
        Coord(unsigned char X, unsigned char Y);

        // the locations can be publically available
        unsigned char x = 0;
        unsigned char y = 0;
};


#endif
