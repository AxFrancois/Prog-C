/*
08/10/21
TP3, ex 3.2

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create an 100 elements array and find the smallest and highest value
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	// Création du tableau avec des nombres aléatoires de 0 à 10000
	srand(time(NULL));
	int tablesize = 100;
	int Tableau[tablesize];
	for(int i=0; i<tablesize; i++){
		Tableau[i] = rand() % 10001;
	}
	
	//Parcours du tableau
	int PlusPetit = Tableau[0];
	int PlusGrand = Tableau[0];
	for(int i=0; i<tablesize; i++){
		if (Tableau[i] > PlusGrand){
			PlusGrand = Tableau[i];
		}
		else if (Tableau[i] < PlusPetit){
			PlusPetit = Tableau[i];
		}
	}
	
	//Affichage du résultat
	printf("Le plus petit élément du tableau est : %d \n", PlusPetit);
	printf("Le plus grand élément du tableau est : %d \n", PlusGrand);

}
