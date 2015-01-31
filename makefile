CC=g++
DIR=bin/
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic -O -c
OBJECTS=$(DIR)Game.o $(DIR)main.o
BIN=$(DIR)me

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN)

$(DIR)Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) -o $(DIR)Game.o Game.cpp

$(DIR)main.o: main.cpp Game.h
	$(CC) $(CFLAGS) -o $(DIR)main.o main.cpp
clean:
	rm -rf $(OBJECTS) $(BIN)
