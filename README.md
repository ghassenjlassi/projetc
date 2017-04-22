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

## Installation et Utilisation

Lancez ColorCalm.
```sh
$ make	
$ ./game
```
Lancez les tests unitaires.
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
$ make clean
``` 
## Autre
Ce projet est en cours de réalisation :)
