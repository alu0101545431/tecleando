CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
OBJ = count_vowels.o count_vowels_main.o

count_vowels.out : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -r count_vowels.out 
	rm -r *.o