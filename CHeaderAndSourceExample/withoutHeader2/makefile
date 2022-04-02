all: main

main.o: main.cpp
	g++ -o main.o main.cpp -c

lib.o: lib.cpp
	g++ -o lib.o lib.cpp -c

main: lib.o main.o
	g++ -o main main.o lib.o
