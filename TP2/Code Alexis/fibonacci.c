/*
Nom du fichier : fibonacci.c
Auteur : Alexis PINCEMIN
Objectif : afficher les n termes de la suite de Fibonacci U0, U1, U2,...Un.
*/

#include <stdio.h> 

int fibonacci(int);

int main(){
	
	int nb_termes;

	printf("Nombre de termes : ");
	scanf("%d", &nb_termes);

	/*Boucle for qui appel la fonction fibonacci pour chaque termes et les affiches*/
	for(int i = 0; i<nb_termes; i++){
		int termes;
		termes = fibonacci(i);
		printf("U%d = %d \n",i, termes);
	}
return 0;
}
/*
Fonction récurrente qui suit la définition de la suite de Fibonacci
Entrée : terme n à calculer
Sortie : valeur du terme n calculé
*/
int fibonacci(int n){
	if(n==0 || n==1){
		return 1;
	}
	else
		return fibonacci(n-1)+fibonacci(n-2);
}




