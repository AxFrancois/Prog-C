/*
Nom du fichier : bits.c
Auteur : Alexis PINCEMIN
Objectif : vérifier si les 4eme et 20eme bits de gauche sont 1 (en binaire). Si les deux bits sont 1, il affiche 1 sinon 0.
*/

#include <stdio.h>  

int main(){

/*entier à analyser*/
    int d = 8;

/*les masques du 4ème et 20ème bits à 1*/
    int mask1 = 524288;
    int mask2 = 8;
    /*Si d et les deux masques font 1 alors on affiche 1 sinon 0*/
    ((d & mask1) && (d & mask2)) ? printf("1") : printf("0");

    return 0;
}

