

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -g
RM = rm -f

SOURCES = CatanObject.cpp Settlement.cpp Road.cpp Card.cpp Player.cpp CatanGame.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

run: main
	./main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $^

%.o: %.cpp %hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) main $(OBJECTS)

PHONY: run clean