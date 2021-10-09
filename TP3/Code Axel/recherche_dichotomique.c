/*
08/10/21
TP3, ex 3.5

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create an 100 elements array use Binary search algorithm to find if a value is inside
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	// Création du tableau avec des nombres aléatoires croissant
	srand(time(NULL));
	int tablesize = 100;
	int Tableau[tablesize];
	Tableau[0] = 1;
	for(int i=1; i<tablesize; i++){
		Tableau[i] = Tableau[i-1] + rand() % 10; 
		//Pour rendre le tableau prévisible, commenter au dessus et décommenter en dessous
		//Tableau[i] = Tableau[i-1] + 2; //tableau des 100 premiers nombre impairs
	}

	//Parcours du tableau
	int NombreAChercher = 48;
	int HasFound = 0;
	int PremierIndice = 0;
	int DernierIndice = tablesize-1;

	while (HasFound != 1 & Tableau[PremierIndice] <= Tableau[DernierIndice]){
		int IndiceAVerif = (DernierIndice + PremierIndice)/2;
		if (Tableau[IndiceAVerif] == NombreAChercher){
			HasFound = 1;
		}
		else if (Tableau[IndiceAVerif] >= NombreAChercher){
			DernierIndice = IndiceAVerif-1;	//Le -1 permet de récupérer le premier élément
		}
		else if (Tableau[IndiceAVerif] <= NombreAChercher){
			PremierIndice = IndiceAVerif+1;	//Le +1 permet de récupérer le dernier élément
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
