/*
15/10/21
TP4, ex 4.7

@Author : Axel François with help from Alexis Pincemin (J'AI SURTOUT BIEN DEBUGGER SON CODE)
https://github.com/AxFrancois/Prog-C/

Creation and read of chained list
*/

#include <stdio.h>
#include "liste.h"
#include <stdlib.h>
#include <time.h>


liste_couleurs* insertion(struct couleur *color,liste_couleurs *li){
	//création nouvelle couleur
	liste_couleurs *new_color;

	new_color = malloc(sizeof(new_color));

	//Attribution à du nouvel élément
	new_color->couleur = color;

	//"si la liste était vide alors l'élément suivant est nulle, sinon il pointe vers le sommet de la pile précédente"
	if(li == NULL){
		new_color->next = NULL;
	}
	else{
		new_color->next = li;
	}

	return new_color;

}

void parcours(liste_couleurs *li)
{
	//si la liste est vide on affiche rien
	if(li == NULL)
	{
		printf("Rien à afficher la liste est vide\n");
		return;
	}
	
	//on parcours la loste tant que celle-ci n'est pas nulle
	int i =0;
	while(li != NULL)
	{
		i++;
		printf("couleur n°%d : rouge : 0x%d vert : 0x%d  bleu : 0x%d alpha : 0x%d \n",i, li->couleur->rouge,li->couleur->vert,li->couleur->bleu,li->couleur->alpha);
		//on déplace le pointeur vers l'élément suivant
		li = li->next;
	}
}

int main(){

	int nbCouleur = 10;
	struct couleur tableauCouleurs[nbCouleur];

	srand(time(NULL));

	for(int j = 0; j < nbCouleur; j++){
		tableauCouleurs[j].rouge = rand() % 256;
		tableauCouleurs[j].vert = rand() % 256;
		tableauCouleurs[j].bleu = rand() % 256;
		tableauCouleurs[j].alpha = rand() % 256;
	}

	liste_couleurs *myList = NULL;

	printf("Appel 1 (liste vide) :\n");
	parcours(myList);

	for(int i = 0; i<nbCouleur; i++)
		myList = insertion(&tableauCouleurs[i],myList);

	printf("Appel 2 (liste non vide) :\n");
	parcours(myList);	
}


