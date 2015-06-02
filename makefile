CC=clang++
BIN=bin/
SRC=src/
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic -O -c -fno-exceptions -std=c++11
OBJECTS=$(BIN)main.o $(BIN)Game.o $(BIN)GameStateManager.o $(BIN)Level.o $(BIN)State.o $(BIN)FrameRateController.o
EXE=$(BIN)me

all: $(OBJECTS)
	mkdir -p $(BIN)
	$(CC) $(OBJECTS) -o $(EXE)

$(BIN)main.o: $(SRC)main.cpp $(SRC)Engine/Game.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)main.o $(SRC)main.cpp

$(BIN)Game.o: $(SRC)Engine/Game.cpp $(SRC)Engine/Game.h $(SRC)Engine/GameStateManager.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)Game.o $(SRC)Engine/Game.cpp

$(BIN)GameStateManager.o: $(SRC)Engine/GameStateManager.cpp $(SRC)Engine/GameStateManager.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)GameStateManager.o $(SRC)Engine/GameStateManager.cpp

$(BIN)Level.o: $(SRC)States/Level.h $(SRC)States/Level.cpp $(SRC)States/State.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)Level.o $(SRC)States/Level.cpp

$(BIN)State.o: $(SRC)States/State.cpp $(SRC)States/State.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)State.o $(SRC)States/State.cpp

$(BIN)FrameRateController.o: $(SRC)Engine/FrameRateController.cpp $(SRC)Engine/FrameRateController.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)FrameRateController.o $(SRC)Engine/FrameRateController.cpp
	

clean:
	rm -rf $(OBJECTS) $(EXE) docs/*
