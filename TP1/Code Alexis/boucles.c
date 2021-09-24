#include <stdio.h>


int main(){


	int i, compteur;

	int ligne = 0;
	int choix =2;
	printf("Nombre de ligne : ");
	scanf("%d" , &compteur);

	while(compteur<4){
		printf("Nombre de ligne : ");
		scanf("%d" , &compteur);
}

switch(choix){

case 1 : 

	for(ligne = 0; ligne < compteur; ligne++){

		printf("*");
		for(i = 2; i<=ligne; i++){
		    if(ligne < compteur-1){printf("#");}
		    else{printf("*");}
		}

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
