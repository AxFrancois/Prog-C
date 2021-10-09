/*
08/10/21
TP3, ex 3.3

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create an 100 elements array and sort them
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	// Création du tableau avec des nombres aléatoires de 0 à 10000 et du tableau trié
	srand(time(NULL));
	int tablesize = 100;
	int Tableau[tablesize];
	int SortedTableau[tablesize];
	for(int i=0; i<tablesize; i++){
		Tableau[i] = rand() % 10001;
	}
	printf("Tableau d'origine : ");
	for(int i=0; i<tablesize; i++){
		printf("%d ",Tableau[i]);
	}
	printf("\n");

	//Parcours du tableau
	for(int i=0; i<tablesize; i++){
		int PlusPetit = Tableau[0];
		int IndexPlusPetit = 0;
		int PlusGrand = Tableau[0];
		for(int j=0; j<tablesize; j++){
			if (Tableau[j] > PlusGrand){
				PlusGrand = Tableau[j];
			}
			else if (Tableau[j] < PlusPetit){
				PlusPetit = Tableau[j];
				IndexPlusPetit = j;
			}
		}
		SortedTableau[i] = PlusPetit;
		Tableau[IndexPlusPetit] = PlusGrand + 1;
	}
	//Affichage du résultat
	printf("Tableau trié : ");
	for(int i=0; i<tablesize; i++){
		printf("%d ",SortedTableau[i]);
	}
	printf("\n");

}
