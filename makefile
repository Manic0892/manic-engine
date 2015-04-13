CC=clang++
BIN=bin/
SRC=src/
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic -O -c -fno-exceptions -std=c++11
OBJECTS=$(BIN)main.o $(BIN)Game.o $(BIN)GameStateManager.o $(BIN)Level.o $(BIN)State.o $(BIN)FrameRateController.o
EXE=$(BIN)me

all: $(OBJECTS)
	mkdir -p $(BIN)
	$(CC) $(OBJECTS) -o $(EXE)

$(BIN)main.o: $(SRC)main.cpp $(SRC)Game.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)main.o $(SRC)main.cpp

$(BIN)Game.o: $(SRC)Game.cpp $(SRC)Game.h $(SRC)GameStateManager.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)Game.o $(SRC)Game.cpp

$(BIN)GameStateManager.o: $(SRC)GameStateManager.cpp $(SRC)GameStateManager.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)GameStateManager.o $(SRC)GameStateManager.cpp

$(BIN)Level.o: $(SRC)Level.h $(SRC)Level.cpp $(SRC)State.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)Level.o $(SRC)Level.cpp

$(BIN)State.o: $(SRC)State.cpp $(SRC)State.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)State.o $(SRC)State.cpp

$(BIN)FrameRateController.o: $(SRC)FrameRateController.cpp $(SRC)FrameRateController.h
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)FrameRateController.o $(SRC)FrameRateController.cpp
	

clean:
	rm -rf $(OBJECTS) $(EXE) docs/*
