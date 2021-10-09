/*
Nom du fichier : puissance.c
Auteur : Alexis PINCEMIN
Objectif : programme qui prend deux entiers a et b et qui affiche la valeur du nombre a élevé à une puissance b
*/

#include <stdio.h>  

int puissance(int*, int*);

int main(){
  
    int b  = 10;
    int a = 2;
    int resultat;

    /*pointeurs de a et de b*/
    int *add_a = &a;
    int *add_b = &b;

    /*appel et affichage du resultat*/
    resultat = puissance(add_a, add_b);
    printf("%d \n", resultat);
    
  return 0;
}

/*Fonction qui calcul un nombre a à la puissance b
Entrées : pointeur de a et de b
Sortie : a^b
*/
int puissance(int *pt_a, int *pt_b){
    int resultat = *pt_a;
    /*boucle for qui multiplie a par lui même à chaque iteration*/
    for(int i = *pt_b; i>1 ; i--){
        resultat *= *pt_a;
    }
    return resultat;
}