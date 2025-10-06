# Makefile for Walter in San Diego game

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lSDL2

TARGET = wisd
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
