/*
Nom du fichier : binaire.c
Auteur : Alexis PINCEMIN
Objectif : afficher un nombre décimal en binaire
*/

#include <stdio.h>

int main(){

	int nombre, i, binaireArray[100];

	printf("Entrez un nombre décimal : ");
	scanf("%d", &nombre);
	int nombreInit = nombre;


/*
Boucle for qui permet de remplir le tableau binaireArray par de 1 ou 0 
en fonction du resultat de l'opération %,
jusqu'a ce que le nombre entré soit égal à 0
*/
	for(i = 0; nombre > 0; i++){
		binaireArray[i] = nombre%2;
		nombre  /= 2;
}
		printf("\n");
		printf("La valeur binaire de %d est : ", nombreInit);

/*
Boucle for qui permet d'afficher le tableau
en commencant par le dernier élément
*/
	for(i-=1; i>=0;i--){
		printf("%d", binaireArray[i]);
        if(i == 0){printf("\n");}
}
return 0;
}