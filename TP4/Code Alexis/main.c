#include <stdio.h>
#include "liste.h"
#include <time.h>
#include <stdlib.h>
#define NOMBRE_COULEURS 10



int main(){

struct couleur tableauCouleurs[NOMBRE_COULEURS];

srand(time(NULL));

for(int j = 0; j < NOMBRE_COULEURS; j++){
	tableauCouleurs[j].rouge = rand() % 256;
	tableauCouleurs[j].vert = rand() % 256;
	tableauCouleurs[j].bleu = rand() % 256;
	tableauCouleurs[j].alpha = rand() % 256;
}

liste_couleurs *myList = NULL;

parcours(myList);

for(int i = 0; i<NOMBRE_COULEURS; i++)
	myList = insertion(&tableauCouleurs[i],myList);


parcours(myList);

for(int i = 0; i<NOMBRE_COULEURS; i++)
	myList = remove_first_color(myList);

parcours(myList);
return 0;
}

