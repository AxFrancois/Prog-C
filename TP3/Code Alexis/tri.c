/*
Nom du fichier : tri.c
Auteur : Alexis PINCEMIN
Objectif : créer un tableau de 100 entiers et le trier par ordre croissant
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void echange(int *, int *);

int main()
{
    int tab[ARRAY_SIZE];
    srand( time( NULL ) );

    /*on génère le tableau de 100 entiers */
    for(int i = 0; i<ARRAY_SIZE; i++){
        tab[i] = rand() %200;
    }

   /*on tri le tableau*/
   int i,j;
   /* on parcours le tableau et on place la plus petite valeur en 1er position ensuite on cherche la deuxième plus petite valeur et on place en 2eme position etc... */
   for(i=0;i<ARRAY_SIZE-1;i++){
       for(j=i+1;j<ARRAY_SIZE;j++){
	  if ( tab[i] > tab[j] ) {
	   echange(&tab[i],&tab[j]);
       	   }
	}
    }
    printf("Tableau trié : ");
     for(int i = 0; i<ARRAY_SIZE; i++){
        printf("%d ", tab[i]);
    }
    return 0;
}

/*
Fonction qui echange deux valeurs
Entrée : pointeur du nombre a et pointeur du nombre b à echanger
Sortie : aucune
*/
void echange(int *pt_a, int *pt_b) {
    int tmp = *pt_a;
    *pt_a = *pt_b;
    *pt_b = tmp;
}





