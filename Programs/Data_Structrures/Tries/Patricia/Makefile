CC=g++
CXXFLAGS=-std=c++17 -g -v
DEPS = patricia.cpp 
OBJ = main.o patricia.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

clean: 
	rm -f *.o
