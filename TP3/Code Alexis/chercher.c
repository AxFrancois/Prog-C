/*
Nom du fichier : chercher.c
Auteur : Alexis PINCEMIN
Objectif : cherchant un entier dans un tableau.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

int main()
{
    int tab[ARRAY_SIZE];
    srand( time( NULL ) );


    /*on génère le tableau de 100 entiers */
    for(int i = 0; i<ARRAY_SIZE; i++){
        tab[i] = rand() %200;
    }


    int valeurChercher = 36;

    /*on parcours le tableau est on compare chaque 
	valeurs à la valeurs recherché */
    for(int i = 0; i<ARRAY_SIZE; i++){
	if(tab[i] == valeurChercher){
		printf("entier présent \n");
	}
    }
    printf("\n");
    return 0;
}


