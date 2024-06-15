

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -g
RM = rm -f

COMMON_SOURCES = CatanObject.cpp Settlement.cpp Road.cpp Card.cpp Player.cpp CatanGame.cpp
MAIN_SOURCES = main.cpp
PLAY_SOURCES = play.cpp
TEST_SOURCES = Test.cpp TestCounter.cpp

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)
PLAY_OBJECTS = $(PLAY_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

run: play
	./play

catan: main
	./main

run_test: test
	./test

main: $(COMMON_OBJECTS) $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $^

play: $(COMMON_OBJECTS) $(PLAY_OBJECTS)
	$(CXX) $(CXXFLAGS) -o play $^

test: $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o test $^

%.o: %.cpp %hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) main play test *.o

.PHONY: run clean main play catan run_test test