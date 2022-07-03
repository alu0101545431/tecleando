CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = source_print.o source_print_main.o

source_print.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r source_print.out 
	rm -r *.o