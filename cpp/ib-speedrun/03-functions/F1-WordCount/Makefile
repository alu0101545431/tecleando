CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = mywc.o mywc_main.o

mywc.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r mywc.out 
	rm -r *.o