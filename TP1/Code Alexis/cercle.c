/*
Nom du fichier : cercle.c
Auteur : Alexis PINCEMIN
Objectif : calculer l'aire et le périmètre d'un cercle
*/

#include <stdio.h>
#include <math.h>

float calculAire(int rayon);
float calculPerimetre(int rayon);

int main(){

	float rayon = 0;
	float perimetre = 0;
	float aire;

	printf("Veuillez entrer le rayon du cercle : ");
	scanf("%f", &rayon);


/*
Appels des fonctions et affichage de l'aire et du périmètre
*/
	printf("perimetre : %f \n", calculPerimetre(rayon));
	printf("aire : %f \n", calculAire(rayon));

	return 0;
}

/*
Fonction qui calcul l'aire du cercle
Entrée : rayon du cercle
Sortie : aire du cercle
*/
float calculAire(int rayon){
	float aire = M_PI*rayon*rayon;
	return aire;
}
/*
Fonction qui calcul le périmètre du cercle
Entrée : rayon du cercle
Sortie : périmètre du cercle
*/
float calculPerimetre(int rayon){
	float perimetre = M_PI*2*rayon;
	return perimetre;
}