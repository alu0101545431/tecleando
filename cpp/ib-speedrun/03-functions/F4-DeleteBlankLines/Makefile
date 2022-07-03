CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = delete.o delete_main.o

delete.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r delete.out 
	rm -r *.o