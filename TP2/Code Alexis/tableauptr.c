/*
Nom du fichier : tableauptr.c
Auteur : Alexis PINCEMIN
Objectif : créer deux tableaux différents : int et float, si l'indice est divisible par 2, 
		   multipliez la valeur à cette position par 3 en utilisant les pointeurs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAB_SIZE 10

int main(){

	int intTab[TAB_SIZE];
	float floatTab[TAB_SIZE];

/*
On rempli les deux tableaux de valeurs aléatoires
*/
srand(time(NULL));
for(int i = 0; i < TAB_SIZE; i++){
	*(intTab+i) = rand() % 256;
	*(floatTab+i) = (float)rand() / 2000;
}

/*
On affiche les deux tableaux avant la manipulation
*/
printf("Valeur avant : \n");
for(int i = 0; i < TAB_SIZE; i++){
	printf("%d ,", *(intTab+i));	
}
printf("\n Valeur avant : \n");
for(int i = 0; i < TAB_SIZE; i++){
	printf("%f ,", *(floatTab+i));
}

/*
On vérifie effectue l'opérations *3 pour les indices divisbles par deux 
sur les 2 tableaux en utilisant les pointeurs 
*/
for(int i = 0; i < TAB_SIZE; i++){	
	if(i %2 ==0){
		*(intTab+i) *=3; 
	}
}
for(int i = 0; i < TAB_SIZE; i++){
	if(i %2 ==0){
		*(floatTab+i) *=3; 
	}
}

/*
On affiche les deux tableaux après la manipulation
*/
printf("\n Valeur après : \n");
for(int i = 0; i < TAB_SIZE; i++){	
	printf("%d ,", *(intTab+i));	
}
printf("\n Valeur après : \n");
for(int i = 0; i < TAB_SIZE; i++){
	printf("%f ,", *(floatTab+i));	
}

return 0;
}
