all : game

game :
	gcc -o game main.c -lm -Wall -Wextra

cunit :
	gcc -o testUnit UnitTests.c -lcunit -lm -Wall -Wextra

doc:
	doxygen doxygen.config

clean:
	rm -f  game
	rm -f testUnit
	rm -rf ./doc
