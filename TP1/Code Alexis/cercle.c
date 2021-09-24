#include <stdio.h>
#include <math.h>

float calculAire(int rayon);
float calculPerimetre(int rayon);


int main(){

	
	float rayon = 0;
	float perimetre = 0;
	float aire;

	printf("Veuillez entrer l'aire du cercle : ");
	scanf("%f", &rayon);

	

	printf("perimetre : %f \n", calculPerimetre(rayon));
	printf("aire : %f \n", calculAire(rayon));

	return 0;
}

float calculAire(int rayon){

	float aire = M_PI*rayon*rayon;

	return aire;}

	
float calculPerimetre(int rayon){

	float perimetre = M_PI*2*rayon;

	return perimetre;}
