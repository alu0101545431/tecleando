CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = substring.o substring_main.o

substring.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r substring.out 
	rm -r *.o