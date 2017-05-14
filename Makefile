all: ColorFlood Solveur

ColorFlood: gameConsole.o grid.o getKey.o
	gcc -o ColorFlood gameConsole.o grid.o getKey.o -lm -Wall -Wextra

Solveur: solver.o grid.o 
	gcc -o Solveur solver.o grid.o -lm -Wall -Wextra

solver.o: src/solver.c src/solver.h src/grid.h 
	gcc -c src/solver.c -Wall -Wextra

grid.o:	src/grid.c src/grid.h
	gcc -c src/grid.c -Wall -Wextra

gameConsole.o: src/gameConsole.c src/gameConsole.h src/grid.h src/getKey.h
	gcc -c src/gameConsole.c -Wall -Wextra

getKey.o: src/getKey.c src/getKey.h
	gcc -c src/getKey.c -Wall -Wextra

clean:
	rm -rf *.o

mrproper: clean
	rm -rf ColorFlood Solveur	
