CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -g3

OFILES := funcs.o
all : app.exe

app.exe : main.o $(OFILES)
	$(CC) -o app.exe main.o $(OFILES)

main.o : main.c funcs.h
	$(CC) $(CFLAGS) -c main.c

funcs.o : funcs.c
	$(CC) $(CFLAGS) -c funcs.c

clean :
	rm *.o *.exe
