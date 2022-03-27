all: main


sayHello.o:sayHello.s
	nasm -f elf64 -o sayHello.o sayHello.s


main:sayHello.o main.c
	gcc -no-pie main.c sayHello.o -o main

clean:
	rm -rf sayHello.o main
