/*
Nom du fichier : liste.c
Auteur : Alexis PINCEMIN
Objectif : Manipuler les listes
*/


#include <stdio.h>
#include "liste.h"
#include <stdlib.h>


liste_couleurs* insertion(struct couleur *color,liste_couleurs *li)
{
	/*création d'un nouveau élément*/
	liste_couleurs *new_color;

	new_color = malloc(sizeof(new_color));

	if(new_color == NULL)
	{
		fprintf(stderr,"erreur allocation dynamique \n");
		exit(EXIT_FAILURE);
	}

	/*on atribut à ce nouveau élément la couleur passé en paramètre*/
	new_color->couleur = color;

	/*si la liste était vide alors l'élément suivant est nulle 
	sinon il pointe vers le sommet de la pile précédente*/
	if(li == NULL)
		new_color->next = NULL;
	else
		new_color->next = li;

	return new_color;

}

liste_couleurs* remove_first_color(liste_couleurs *li)
{
	if(li == NULL)
		return li;
	
	liste_couleurs *new_color;

	new_color = li->next;

	free(li);
	li = NULL;

	return new_color;
}

void parcours(liste_couleurs *li)
{
	/*si la liste est vide on affiche rien*/
	if(li == NULL)
	{
		printf("Rien à afficher la liste est vide\n");
		return;
	}
	int i =0;

	/*on parcours la loste tant que celle-ci n'est pas nulle*/
	while(li != NULL)
	{
		++i;
		printf("couleur n°%d : rouge : 0x%d vert : 0x%d  bleu : 0x%d alpha : 0x%d \n",i, li->couleur->rouge,li->couleur->vert,li->couleur->bleu,li->couleur->alpha);
		/*on déplace le pointeur du sommet de la pile*/
		li = li->next;
	}
}
