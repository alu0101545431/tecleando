CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = to_number.o to_number_main.o

to_number.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r to_number.out 
	rm -r *.o