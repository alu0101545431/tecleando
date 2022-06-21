CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = encrypt.o encrypt_main.o

encrypt.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r encrypt.out 
	rm -r *.o