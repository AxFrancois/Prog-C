/*
Nom du fichier : operateurs.c
Auteur : Alexis PINCEMIN
Objectif : testez les différents opérateurs arithmétiques et logiques
*/

#include <stdio.h>


int main(){

	int a = 16;
	int b = 3;

	/*opérateurs logiques*/
	printf("non a : %d \n" , !a);
	printf("a et b : %d \n" , a && b);
	printf("a ou b : %d \n", a || b);

	/*operateurs arithmetiques*/
	printf("a + b : %d \n" , b+a);
	printf("a - b : %d \n" , a-b);
	printf("a * b : %d \n", a*b);
	printf("a/b : %d \n", a/b);
	printf("a % b : %d \n", a%b);

	return 0;
}