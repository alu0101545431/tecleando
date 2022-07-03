CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = find.o find_main.o

find.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r find.out 
	rm -r *.o