all : sortie 

sortie :
	gcc -o sortie UnitTests.c -lcunit -lm 

doc:
	doxygen doxygen.config


clean:
				rm -f  sortie 
				rm -rf ./doc