CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = acronym.o acronym_main.o

acronym.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r acronym.out 
	rm -r *.o