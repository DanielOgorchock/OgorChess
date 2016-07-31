# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
CFLAGS  = -Wall -lm -Iinclude

# the build target executable:
TARGET = build/OgorChess

default: OgorChess

all: OgorChess

OgorChess: ogorchess.o Piece.o Coord.o Board.o
	$(CC) $(CFLAGS) -o OgorChess ogorchess.o Piece.o Coord.o Board.o Rook.o Knight.o Bishop.o Queen.o King.o Pawn.o

ogorchess.o: src/ogorchess.cpp
	$(CC) $(CFLAGS) -c -o ogorchess.o src/ogorchess.cpp

Piece.o: include/Piece.h src/Piece.cpp Coord.o
	$(CC) $(CFLAGS) -c -o Piece.o src/Piece.cpp

Coord.o: include/Coord.h src/Coord.cpp
	$(CC) $(CFLAGS) -c -o Coord.o src/Coord.cpp
	
Board.o: include/Board.h src/Board.cpp Piece.o Rook.o Knight.o Bishop.o Queen.o King.o Pawn.o
	$(CC) $(CFLAGS) -c -o Board.o src/Board.cpp

Rook.o: include/Rook.h src/Rook.cpp Piece.o
	$(CC) $(CFLAGS) -c -o Rook.o src/Rook.cpp

Knight.o: include/Knight.h src/Knight.cpp Piece.o
	$(CC) $(CFLAGS) -c -o Knight.o src/Knight.cpp

Bishop.o: include/Bishop.h src/Bishop.cpp Piece.o
	$(CC) $(CFLAGS) -c -o Bishop.o src/Bishop.cpp

Queen.o: include/Queen.h src/Queen.cpp Piece.o
	$(CC) $(CFLAGS) -c -o Queen.o src/Queen.cpp

King.o: include/King.h src/King.cpp Piece.o
	$(CC) $(CFLAGS) -c -o King.o src/King.cpp

Pawn.o: include/Pawn.h src/Pawn.cpp Piece.o
	$(CC) $(CFLAGS) -c -o Pawn.o src/Pawn.cpp

clean:
	rm -f *.o OgorChess





