main.exe : funcs.o io.o
	gcc -o main.exe funcs.o io.o

funcs.o : funcs.c funcs.h
	gcc -std=c99 -Wall -Werror -pedantic -c funcs.c

io.o : io.c io.h
	gcc -std=c99 -Wall -Werror -pedantic -c io.c

main.o : main.c funcs.h io.h
	gcc -std=c99 -Wall -Werror -pedantic -c funcs.c

clean :
	rm *.o *.exe
