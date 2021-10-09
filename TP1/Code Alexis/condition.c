/*
Nom du fichier : conditions.c
Auteur : Alexis PINCEMIN
Objectif : affichage de numéros <= 1000 qui sont divisible par:
a. 2 et 15
b. 103 ou 107
c. 7 ou 5, mais pas par 3
*/

#include <stdio.h>

int main(){

	int numeros[1001];

	for(int compteur = 1; compteur <= 1000; compteur++){
		/*on initialise le tableau numéro*/
        numeros[compteur]= compteur;

        /* pour chaque élément on regarde si il respecte les critères, si c'est le cas alors on affiche ces prorpiétés*/
		if( numeros[compteur]%2 == 0 && numeros[compteur]%15 == 0){
			printf("%d est divisble par 2 et 15 \n", numeros[compteur]);	
		}
		else if( numeros[compteur]%103 == 0 && numeros[compteur]%107 == 0){
			printf("%d est divisble par 103 et 107 \n", numeros[compteur]);	
		}
		else if( (numeros[compteur]%7 == 0 || numeros[compteur]%5 == 0) && numeros[compteur]%3 == 1 ){
			printf("%d est divisble par 7 ou 5 mais par par 3 \n", numeros[compteur]);	
		}
        }

	return 0;
}