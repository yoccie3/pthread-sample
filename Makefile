main: main.c
	gcc -Wall -O2 -o main main.c -lpthread

clean:
	rm -rf main
