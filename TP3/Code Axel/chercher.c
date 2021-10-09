/*
08/10/21
TP3, ex 3.4

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create an 100 elements array and search if a certain value is present
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
	//Ligne à décommenter pour faire apparaitre un nombre à coup sûr
	//Tableau[1] = 5;

	//Parcours du tableau
	int NombreAChercher = 5;
	int HasFound = 0;
	for(int i=0; i<tablesize; i++){
		if (Tableau[i] == NombreAChercher){
			HasFound = 1;
		}
	}
	
	//Affichage du résultat
	if (HasFound == 1){
		printf("Entier présent \n");
	}
	else{
		printf("Entier absent \n");
	}
}
