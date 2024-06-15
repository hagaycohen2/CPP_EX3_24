

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -g
RM = rm -f

COMMON_SOURCES = CatanObject.cpp Settlement.cpp Road.cpp Card.cpp Player.cpp CatanGame.cpp
MAIN_SOURCES = main.cpp
PLAY_SOURCES = play.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
PLAY_OBJECTS = $(PLAY_SOURCES:.cpp=.o)

run: play
	./play

catan: main
	./main

main: $(COMMON_OBJECTS) $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $^

play: $(COMMON_OBJECTS) $(PLAY_OBJECTS)
	$(CXX) $(CXXFLAGS) -o play $^

%.o: %.cpp %hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) main $(COMMON_OBJECTS) $(MAIN_OBJECTS) $(PLAY_OBJECTS)

.PHONY: run clean main play catan