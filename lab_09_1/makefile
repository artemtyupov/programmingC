CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic -g3

all : app.exe

app.exe : main.o
	$(CC) -o app.exe main.o

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

clean :
	rm *.o *.exe *.creator.user.* *.creator.user