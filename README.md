# ColorCalm
## Prerequis
Gcc 6.3.0
```sh
$ sudo apt install gcc	
```
CUnit(pour les tests unitaires)
```sh
$ sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
```

Doxygen(pour généner la doc)
```sh
$ sudo apt install doxygen graphviz
```
Valgrind(test des fuites memoires)
```sh
$ sudo apt install valgrind
```

## Installation et Utilisation

Lancez ColorCalm.
```sh
$ make	
$ ./ColorFlood
```
Lancez les tests unitaires(avec CUnit).
```sh
$ make cunit
$ ./unitTest
``` 
## Documentation
Génération de la doc avec la commande
```sh
$ make doc
``` 
la doc est dispo au format HTML dans ./Doc/html/index.html

## Désinstallation/Nettoyage
```sh
$ make mrproper
``` 
## Test des fuites mémoires
```sh
$ make cunit
$ valgrind --leak-check=full --show-leak-kinds=all ./testUnit
$ valgrind --leak-check=full --show-leak-kinds=all ./ColorFlood
```
