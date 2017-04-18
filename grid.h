typedef char ** grid;

//creation de la grille dynamiquement -> maloc/caloc/...
grid initGrid(int size);

// destruction de la grille, liberation memoire -> free
void releaseGrid(grid board);

// init de la grille avec des couleurs au hasard -> random()
bool setGridRandom(grid &board);

//init de la grille avec un fichier 
bool setGridFromFile(grid &board,char* file);

//change la couleur d'un case en x,y par la couleur f
bool changeCaseColor(grid &board,int x,int y,char color);

/* je sais pas */ identCompo4Connexe(/*je sais pas ^^ */);

// effectue un flood sur lagrille en fonction de la case selectionne, chercher algo du pot de peinture ou de remplissage sur google
void colorFlood(grid &board,int x,int y,char color);

// test si toute la grille a la meme couleur partout, revoi un bool
bool testGridFull(grid board);
