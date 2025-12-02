all:
	clang $(wildcard *.c) -o program -Wall -g -O0 -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl -lrt -lX11
clean:
	rm -f program
