all: dz7

dz7: main.o test.o
	g++ -std=c++11 -g main.o test.o -o dz7.out
	rm -r *.o

main.o:
	g++ -std=c++11 -c main.cpp

test.o:
	g++ -std=c++11 -c ./lib/test_my_unordered_set.cpp -o test.o
	
	
