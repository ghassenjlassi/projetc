
all: grid
cunit:  ../home/asus/Bureau/projetc/OCalm/UnitTests  ../home/asus/Bureau/projetc/OCalm/grid.o
	cc $(LDFLAGS)  ../home/asus/Bureau/projetc/OCalm/grid.o ../home/asus/Bureau/projetc/OCalm/UnitTests -o cunit



cunit:  ../bin/test.o  ../bin/gamelogic.o ../bin/set.o
				cc $(LDFLAGS)  ../bin/gamelogic.o ../bin/test.o ../bin/set.o    -o cunit

ui:../home/asus/Bureau/projetc/OCalm/grid.o 
				cc $(LDFLAGS) ../home/asus/Bureau/projetc/OCalm/grid.o -o flood


grid: grid.o
	gcc -o grid grid.o

grid.o: grid.c
	gcc -o grid.o -c grid.c -W -Wall -ansi -pedantic

doc:
	doxygen doxygen.config
run: ui
	./flood
clean:
				rm -f  ../home/asus/Bureau/projetc/OCalm/*.o core
valgrind: cunit
	valgrind --leak-check=yes ./cunit
mrproper: clean
				rm -f flood
				rm -f cunit
