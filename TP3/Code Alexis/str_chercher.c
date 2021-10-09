/*
Nom du fichier : str_chercher.c
Auteur : Alexis PINCEMIN
Objectif : créer un tableau de 10 phrases (un tableau de tableau de caractères). Sans utilisant les fonctions de bibliothèques standards ou externes, cherchez si une phrase est dans le tableau ou pas.
*/

#include <stdio.h>
#include <string.h>

int calculNbCaracteres(char *);

int main(){

char tableauPhrase[10][250]  =  {{"Afin de circonvenir à la politique actuelle"},
				{"il est très important d'arrêter de stigmatiser"},
				{"la somme des ouvertures possibles"},
				{"parce que la nature a horreur du vide"},
				{"Si vous voulez mon avis concernant la dégradation contextuelle"},
				{"il ne faut pas s'interdire de remodeler la somme"},
				{"des synergies opportunes, pour longtemps"},
				{"Avec la baisse de confiance de l'époque actuelle"},
				{"il est très important d'essayer la globalité des améliorations"},
				{"s'offrant à nous, à long terme."}};

char phraseRechercher[250]= {"Afin de circonvenirt à la politique actuelle"};
int taillePhraseRechercher =  calculNbCaracteres(phraseRechercher);

/*boucle qui parcours les 10 phrases*/
for(int i = 0; i < 10; i++){
	/*boucle qui parcours chaque caractère des 10 phrases*/
	for(int j = 0; j < calculNbCaracteres(tableauPhrase[i]); j++){
		/* si les deux phrases font la même taille alors on les compare sinon on passe à la suivante*/ 
		if(taillePhraseRechercher == calculNbCaracteres(tableauPhrase[i])){
			if(tableauPhrase[i][j] == phraseRechercher[j]){
				printf("phrase présente \n");
				return 0;}
		}
	}	
}
printf("phrase non présente \n");
return 0;

}

int calculNbCaracteres(char *texte1){
	int compteur =0;		
	int i = 0;

	/*Boucle while infini tant que l'élement i de la chaine est diférent de /0
	le nombre d'itération est enregistré dans la variable compteur  */
	while(1){		
		if(texte1[i] != '\0'){++compteur;}
		else{break;}
		++i;
	}
	return compteur;
}