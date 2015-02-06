CC=g++
BIN=bin/
SRC=src/
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic -O -c
OBJECTS=$(BIN)main.o $(BIN)Game.o $(BIN)GameStateManager.o $(BIN)Level.o
EXE=$(BIN)me

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

$(BIN)main.o: $(SRC)main.cpp $(SRC)Game.h
	$(CC) $(CFLAGS) -o $(BIN)main.o $(SRC)main.cpp

$(BIN)Game.o: $(SRC)Game.cpp $(SRC)Game.h $(SRC)GameStateManager.h
	$(CC) $(CFLAGS) -o $(BIN)Game.o $(SRC)Game.cpp

$(BIN)GameStateManager.o: $(SRC)GameStateManager.cpp $(SRC)GameStateManager.h
	$(CC) $(CFLAGS) -o $(BIN)GameStateManager.o $(SRC)GameStateManager.cpp

$(BIN)Level.o: $(SRC)Level.cpp $(SRC)State.h
	$(CC) $(CFLAGS) -o $(BIN)Level.o $(SRC)Level.cpp


clean:
	rm -rf $(OBJECTS) $(EXE)
