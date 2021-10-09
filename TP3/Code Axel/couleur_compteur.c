/*
08/10/21
TP3, ex 3.7

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create a table of 100 colors and count how many time each color is present
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	//tableau de 100 couleurs
	struct couleur{
		unsigned char rouge;
		unsigned char vert;
		unsigned char bleu;
		unsigned char alpha;	
	};
	srand(time(NULL));
	int nombreCouleur = 100;
	struct couleur BeautifulColors[nombreCouleur];
	for(int i=0; i<nombreCouleur; i++){
		int nombreRandom = rand() % 10;
		BeautifulColors[i].rouge = 0x10*nombreRandom;
		BeautifulColors[i].vert = 0x10*nombreRandom;
		BeautifulColors[i].bleu = 0x10*nombreRandom;
		BeautifulColors[i].alpha = 0x10*nombreRandom;
	}

	//tableau de comptage
	struct couleurComptage{
		unsigned char rouge;
		unsigned char vert;
		unsigned char bleu;
		unsigned char alpha;	
		unsigned int count;
	};
	struct couleurComptage DifferentColors[nombreCouleur];
	for(int i=0; i<nombreCouleur; i++){
		DifferentColors[i].rouge = 0;
		DifferentColors[i].vert = 0;
		DifferentColors[i].bleu = 0;
		DifferentColors[i].alpha = 0;
		DifferentColors[i].count = 0;
	}


	//parcours
	for(int i=0; i<nombreCouleur; i++){
		for(int j=0; j<nombreCouleur; j++){
			if (DifferentColors[j].count == 0){
				DifferentColors[j].rouge = BeautifulColors[i].rouge;
				DifferentColors[j].vert = BeautifulColors[i].vert;
				DifferentColors[j].bleu = BeautifulColors[i].bleu;
				DifferentColors[j].alpha = BeautifulColors[i].alpha;
				DifferentColors[j].count = 1;
				break;	
			}
			else if(DifferentColors[j].rouge == BeautifulColors[i].rouge & DifferentColors[j].vert == BeautifulColors[i].vert & DifferentColors[j].bleu == BeautifulColors[i].bleu & DifferentColors[j].alpha == BeautifulColors[i].alpha){
				DifferentColors[j].count++;
				break;	
			}
		}			
	}

	printf("Couleurs uniques : \n");
	for(int i=0; i<nombreCouleur; i++){
		if (DifferentColors[i].count == 0){
			break;
		}
		printf("r : %x, v : %x, b : %x, a : %x, Comptage : %d\n", DifferentColors[i].rouge, DifferentColors[i].vert, DifferentColors[i].bleu, DifferentColors[i].alpha, DifferentColors[i].count);
	}

}
	
