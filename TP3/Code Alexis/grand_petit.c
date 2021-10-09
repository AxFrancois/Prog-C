/*
Nom du fichier : grand_petit.c
Auteur : Alexis PINCEMIN
Objectif : créer un tableau de 100 entiers et calculer le numéro le plus grand et le plus petit
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tab[100];
    srand( time( NULL ) );

    /*on génère le tableau de 100 entiers */
    for(int i = 0; i<100; i++){
        tab[i] = rand() %200;
    }

    /*on parcours le tableau de 100 entiers et on compare 
    chaque valeur à la valeur max précedente en commencant la comparaison avec 0*/
    int maxValue = 0;
    for(int i = 0; i<100; i++){
        if(tab[i] >= maxValue){
            maxValue = tab[i];
        }
    }

    /*on parcours le tableau de 100 entiers et on compare
     chaque valeur à la valeur min précedente en commencant la comparaison avec la valeur max*/
    int minValue = maxValue;
    for(int i = 0; i<100; i++){
        if(tab[i] <= minValue){
            minValue = tab[i];
        }
    }

    printf(" La valeur max du tableau est : %d \n", maxValue);
    printf(" La valeur min du tableau est : %d \n", minValue);

    return 0;
}