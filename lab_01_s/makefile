main.exe : area.o main.o tests.o
	gcc -o main.exe area.o main.o tests.o

tests.exe : tests.o main.o area.o
	gcc -o tests.exe tests.o main.o area.o

tests.o : tests.c tests.h area.h
	gcc -std=c99 -Wall -Werror -pedantic -c tests.c

area.o : area.c area.h
	gcc -std=c99 -Wall -Werror -pedantic -c area.c

main.o : main.c area.h tests.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c

clean :
	rm *.o *.exe
