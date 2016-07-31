# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
CFLAGS  = -Wall -lm -Iinclude

# the build target executable:
TARGET = build/OgorChess

default: OgorChess

all: OgorChess

OgorChess: ogorchess.o
	$(CC) $(CFLAGS) -o OgorChess ogorchess.o

ogorchess.o: src/ogorchess.cpp
	$(CC) $(CFLAGS) -c -o ogorchess.o src/ogorchess.cpp

clean:
	rm -f build/*
