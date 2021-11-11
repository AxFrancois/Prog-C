/*
Nom du fichier : factorielle.c
Auteur : Alexis PINCEMIN
Objectif : apréhender les fonctions récursives
*/
#include <stdio.h>

int factorielle (int num);

int main()
{
    printf("%d \n", factorielle(5));
    return 0;
}

int factorielle(int num){
    if(num == 0)
        return 1;
    else
        return(num*factorielle(num-1));
}
