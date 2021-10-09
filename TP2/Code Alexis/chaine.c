/*
Nom du fichier : chaine.c
Auteur : Alexis PINCEMIN
Objectifs : calcule le nombre de caractères dans une chaine de caractères
			copie une chaine de caractères dans une autre chaine de caractère
			concatène deux chaines de caractères
*/

#include <stdio.h> 

int calculNbCaracteres(char *);
void copyChaineCaracteres(char *, char *);
void concatenationsChaineCaracteres(char *, char *, char*);

int main(){

	char texte1[] = "Bonjour ";
	char texte2[] = "tout le monde !!";
	char texte1_concatene[calculNbCaracteres(texte1)+calculNbCaracteres(texte2)];
	char texte_copy[calculNbCaracteres(texte1)];

	/*appel de la fonction de calcul de longueur et affichage de la longueur de la chaine /
	printf("la chaine contient %d caractères \n", calculNbCaracteres(texte1));
	
	/*appel de la fonction de recopie et affichage de la chaine copiée*/
	copyChaineCaracteres(texte1, texte_copy);
	printf("texte copié : ");
	for(int i = 0; i< calculNbCaracteres(texte1); i++){
		printf("%c", texte_copy[i]);
		if(i == calculNbCaracteres(texte1) -1){printf("\n");}
	}

	/*appel de la fonction de concatenation et affichage de la chaine concatené*/
	concatenationsChaineCaracteres(texte1,texte2, texte1_concatene);	
	for(int i = 0; i< calculNbCaracteres(texte1_concatene); i++){
		printf("%c", texte1_concatene[i]);
		if(i == calculNbCaracteres(texte1_concatene)){printf("\n");}
	}
	return 0;
}

/*
Fonction qui renvoie la longueur d'une chaine de caractère
Entrée : chaine à analyser
Sortie : longueur de la chaine
*/
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
/*
Fonction qui copie une chaine de caractère dans une autre chaine de caractère
Entrée : chaine à copier, chaine à initialiser
Sortie : aucune
*/
void copyChaineCaracteres(char *texte1, char *copy){
	/*on parcourt la chaine initial pour copier chacun de ses élement dans la chaine recopie
	le nombre d'iteration est défini par la longueur le chaine inital*/
	for(int i = 0; i< calculNbCaracteres(texte1); i++){
		copy[i] = texte1[i];
	}	
}

/*
Fonction qui concatène deux chaine de caractères
Entrée : chaine1, chaine 2, chaine1+2
Sortie : aucune
*/
void concatenationsChaineCaracteres(char *texte1, char *texte2, char *texte1_complet){
	int i;
	/*on parcourt la chaine1 pour copier chacun de ses élement dans la chaine1+2
	le nombre d'iteration est défini par la longueur le chaine1*/
	for(i = 0; i< calculNbCaracteres(texte1); i++){
		texte1_complet[i] = texte1[i];	
	}

	/*la variable tmp sert à reprendre le remplissage de la chaine1+2*/
	int tmp = i;
	/*on parcourt la chaine2 pour copier chacun de ses élement dans la chaine1+2
	le nombre d'iteration est défini par la longueur le chaine2*/
	for(i =0; i < calculNbCaracteres(texte2); i++){
		texte1_complet[tmp + i] = texte2[i];		
	}	
}

