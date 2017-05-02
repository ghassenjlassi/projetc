all : game

game :
	gcc -o game src/gameConsole.c -lm -Wall -Wextra

gameGUI : 
	gcc -o gameGUI src/gameGUI.c -lm -lSDL -Wall -Wextra 

test : 
	gcc -o test src/main.c -lm -Wall -Wextra

cunit :
	gcc -o testUnit src/UnitTests.c -lcunit -lm -Wall -Wextra

doc:
	doxygen doxygen.config

clean:
	rm -f  game gameGUI test testUnit
	rm -rf ./doc
