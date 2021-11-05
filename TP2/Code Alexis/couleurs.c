/*
Nom du fichier : couleurs.c
Auteur : Alexis PINCEMIN
Objectif : créez et initialisez un tableau de 10 couleurs en utilisant struct.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){

/*
On créer la struct couleur avec les 4 paramètres
*/
typedef struct couleur{
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
	unsigned char alpha;
}couleur;

srand(time(NULL));

/*
On créer le tableaux des 10 couleurs
*/
couleur tableauCouleurs[10];

/*
On rempli initialise les valeurs rgba pour les 10 couleurs
*/
for(int i = 0; i < 10; i++){

	int a = rand() % 256;
	int b = rand() % 256;
	int c = rand() % 256;
	int d = rand() % 256;

	tableauCouleurs[i].rouge = a;
	tableauCouleurs[i].vert = b;
	tableauCouleurs[i].bleu = c;
	tableauCouleurs[i].alpha = d;
}
printf("\n");

/*
On affiche chacune des couleurs
*/
for(int i = 0; i < 10; i++){
	printf("couleur %d : rouge = 0x%x, vert = 0x%x, bleu = 0x%x, alpha = 0x%x \n",i+1,  tableauCouleurs[i].rouge,tableauCouleurs[i].vert,
	tableauCouleurs[i].bleu,tableauCouleurs[i].alpha);
}
return 0;
}

