/*
01/10/21
TP2, ex 2.7

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create an array of 10 colors using struct
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	struct couleur{
		unsigned char rouge;
		unsigned char vert;
		unsigned char bleu;
		float alpha;	//c'est en général exprimé entre 0 et 1 c'est plus pratique même si ça respecte pas exactement la consigne
	};
	
	srand(time(NULL));
	int nombreCouleur = 10;
	struct couleur BeautifulColors[nombreCouleur];
	
	for(int i=0; i<nombreCouleur; i++){
		BeautifulColors[i].rouge = rand() % 256;
		BeautifulColors[i].vert = rand() % 256;
		BeautifulColors[i].bleu = rand() % 256;
		BeautifulColors[i].alpha = rand() % 256;
	}
	
	for(int i=0; i<nombreCouleur; i++){
		printf("r : %d, v : %d, b : %d, a : %f\n", BeautifulColors[i].rouge, BeautifulColors[i].vert, BeautifulColors[i].bleu, BeautifulColors[i].alpha/256);
	}
}
	
