sayHello.o:
	as -o sayHello.o sayHello.S


main:
	gcc -no-pie main.c sayHello.o -o main

clean:
	rm -rf *.o