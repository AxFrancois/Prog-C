/*
Nom du fichier : couleur_compteur.c
Auteur : Alexis PINCEMIN
Objectif : comptez le nombre de couleurs identique dans un tableau de 100 couleurs.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NOMBRE_COULEURS 100

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
On créer le tableaux des 100 couleurs
*/
couleur tableauCouleurs[NOMBRE_COULEURS];

/*
On rempli initialise les valeurs rgba pour les 100 couleurs
*/
for(int i = 0; i < NOMBRE_COULEURS; i++){

	tableauCouleurs[i].rouge = rand() % 256;
	tableauCouleurs[i].vert = rand() % 256;
	tableauCouleurs[i].bleu = rand() % 256;
	tableauCouleurs[i].alpha = rand() % 256;
}


typedef struct couleurCompte{
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
	unsigned char alpha;
	unsigned int compteur;
}couleurCompte;


couleurCompte tabCouleursCompte[NOMBRE_COULEURS];

for(int i=0; i<NOMBRE_COULEURS; i++){
	tabCouleursCompte[i].rouge = 0;
	tabCouleursCompte[i].vert = 0;
	tabCouleursCompte[i].bleu = 0;
	tabCouleursCompte[i].alpha = 0;
	tabCouleursCompte[i].compteur = 0;
}

/*boucle qui parcours les couleurs les unes après les autres*/
for(int i = 0; i < NOMBRE_COULEURS; i++){
	/*boucle for qui parcours toutes les couleurs*/
	for(int j = 0; j < NOMBRE_COULEURS; j++){
		/* si la couleur n'est pas encore comptabilisé on l'ajoute et on initialise à 1 les compteurs*/
		if(tabCouleursCompte[j].compteur == 0){
			tabCouleursCompte[j].rouge = tableauCouleurs[i].rouge;
			tabCouleursCompte[j].vert = tableauCouleurs[i].vert;
			tabCouleursCompte[j].bleu = tableauCouleurs[i].bleu;
			tabCouleursCompte[j].alpha = tableauCouleurs[i].alpha;
			tabCouleursCompte[j].compteur = 1;
			break;
		/*si on a déjà rencontré la valeur alors on la compart avec la valeur actuelle qui se trouve en i*/
		}else if(tableauCouleurs[i].rouge == tableauCouleurs[j].rouge && tableauCouleurs[i].vert == tableauCouleurs[j].vert && tableauCouleurs[i].bleu == tableauCouleurs[j].bleu && tableauCouleurs[i].alpha == tableauCouleurs[j].alpha){
			++tabCouleursCompte[j].compteur;
			break;

		}
	}
}

/*on affiche uniquement les couleurs qui ont été ajouté dans le tableau != 0*/
int numeroCouleur = 0;
for(int i = 0; i < NOMBRE_COULEURS; i++){
	if((tabCouleursCompte[i].rouge && tabCouleursCompte[i].vert && tabCouleursCompte[i].bleu && tabCouleursCompte[i].alpha) != 0){
	++numeroCouleur;
	printf("couleur %d : rouge = 0x%x, vert = 0x%x, bleu = 0x%x, alpha = 0x%x %d\n",numeroCouleur,tabCouleursCompte[i].rouge,tabCouleursCompte[i].vert,
	tabCouleursCompte[i].bleu,tabCouleursCompte[i].alpha,tabCouleursCompte[i].compteur);
	}
}
return 0;
}

