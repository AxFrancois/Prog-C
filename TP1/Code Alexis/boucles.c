/*
Nom du fichier : boucles.c
Auteur : Alexis PINCEMIN
Objectif : utiliser for, # et * et qui affiche un triangle rectangle.
*/


#include <stdio.h>

int main(){

	int i, compteur;
	int ligne = 0;
	int choix =1;

	printf("Nombre de ligne : ");
	scanf("%d" , &compteur);

/*verifier le nombre de lignes entrées*/
	while(compteur<4){
		printf("Nombre de ligne : ");
		scanf("%d" , &compteur);
    }

switch(choix){

case 1 : 

/*Boucle for qui affiche chaque ligne*/
	for(ligne = 0; ligne < compteur; ligne++){
		
        printf("*"); /*on affiche * dans tous les cas*/
		/*Boucle for qui affiche # si on est au moins à la 3ème ligne (ligne =2) et pas à la dernière alors 
        on affiche # si on est la dernière ligne (ligne = compteur-1) alors on affiche * */
        for(i = 2; i<=ligne; i++){
		    if(ligne < compteur-1){printf("#");}
		    else{printf("*");}
		}
        /*Si on est au moins à la 2ème ligne on affiche une * */
		if(ligne>= 1){printf("*");}
		printf("\n");
	}
break;

case 2 :
	 
	while(ligne < compteur){
		printf("*");
		for(i = 2; i<=ligne; i++){
		    if(ligne < compteur-1){printf("#");}
		    else{printf("*");}
		}
		if(ligne>= 1){printf("*");}
		printf("\n");
	
	++ligne;
	}
	
break;
case 3 : 
	do{
		printf("*");
		for(i = 2; i<=ligne; i++){
		    if(ligne < compteur-1){printf("#");}
		    else{printf("*");}
		}
		if(ligne>= 1){printf("*");}
		printf("\n");
		++ligne;
	}while(ligne < compteur);
break;
		
}
return 0;
}
