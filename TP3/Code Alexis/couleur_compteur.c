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


couleur tabCouleursCompte[NOMBRE_COULEURS];


/*boucle qui parcours les couleurs*/
for(int i = 0; i < NOMBRE_COULEURS-1; i++){
	/*compteur renitialisé à chaque couleur*/
	int compteur = 1;
	/*boucle for qui parcours les couleurs qui se trouve après la ième*/
	for(int j = i+1; j < NOMBRE_COULEURS; j++){
		/* on compare la couleur i avec les couleurs suivantes si elles sont égales alors les ajoutes dans le tableau des couleur comptés après avoir vérifié qu'elles n'y était pas déjà et on incrémente sinon on l'ajoute uniquement*/
		if(tableauCouleurs[i].rouge == tableauCouleurs[j].rouge && tableauCouleurs[i].vert == tableauCouleurs[j].vert && tableauCouleurs[i].bleu == tableauCouleurs[j].bleu && tableauCouleurs[i].alpha == tableauCouleurs[j].alpha){
			/*boucle for qui permet de parcourir le tableau des couleurs comptées*/
			for(int h = 0; h < NOMBRE_COULEURS; h++){
				/*on compare la couleur ième avec les couleurs déjà pésente dans le tableau des couleurs comptées si elle n'y est pas alors on l'ajoute sinon on incrémente le compteur*/
				if(tabCouleursCompte[h].rouge != tableauCouleurs[i].rouge || tabCouleursCompte[h].vert != tableauCouleurs[i].vert || tabCouleursCompte[h].bleu != tableauCouleurs[i].bleu || tabCouleursCompte[h].alpha != tableauCouleurs[i].alpha){
				tabCouleursCompte[i].rouge = tableauCouleurs[i].rouge;
				tabCouleursCompte[i].vert = tableauCouleurs[i].vert;
				tabCouleursCompte[i].bleu = tableauCouleurs[i].bleu;
				tabCouleursCompte[i].alpha = tableauCouleurs[i].alpha;
				}
				else
					++compteur;
			}
		}
		else{
			    tabCouleursCompte[i].rouge = tableauCouleurs[i].rouge;
				tabCouleursCompte[i].vert = tableauCouleurs[i].vert;
				tabCouleursCompte[i].bleu = tableauCouleurs[i].bleu;
				tabCouleursCompte[i].alpha = tableauCouleurs[i].alpha;
		}
	}
	/*à chaque itération de la boucle for (i) on affiche les couleurs ajouter dans le tableau des couleurs comptées*/
	printf("couleur %d : rouge = 0x%x, vert = 0x%x, bleu = 0x%x, alpha = 0x%x %d\n",i+1,tabCouleursCompte[i].rouge,tabCouleursCompte[i].vert,
	tabCouleursCompte[i].bleu,tabCouleursCompte[i].alpha, compteur);
}
return 0;
}

