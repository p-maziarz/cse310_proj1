CXX = clang++
CXXFLAGS = -std=gnu++14 -fcolor-diagnostics -fansi-escape-codes -g

SRC = main.cpp hash.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = encoder

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

main.o: main.cpp hash.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

hash.o: hash.cpp hash.h
	$(CXX) $(CXXFLAGS) -c hash.cpp -o hash.o

clean:
	rm -f $(OBJ) $(EXECUTABLE)
