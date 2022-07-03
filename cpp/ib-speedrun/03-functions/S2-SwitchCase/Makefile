CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = switch_case.o switch_case_main.o

switch_case.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r switch_case.out 
	rm -r *.o