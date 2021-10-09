/*
01/10/21
TP2, ex 2.9

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program create two different arrays (int and float) and if the index is divisible by 2, multiply the value at that position by 3 using only pointers.
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
	srand(time(NULL));
	int tailleTableau = 3;
	int TableauInt[3] = {rand() % 256, rand() % 256, rand() % 256};
	float TableauFloat[3] = {rand() % 256, rand() % 256, rand() % 256};
	
	printf("Valeurs d'origine tableau int : %d, %d, %d\n", TableauInt[0], TableauInt[1], TableauInt[2]);
	printf("Valeurs d'origine tableau float : %f, %f, %f\n", TableauFloat[0], TableauFloat[1], TableauFloat[2]);
	for(int i=0; i<tailleTableau; i++){
		if (i % 2 == 0){
			*(TableauInt+i) = *(TableauInt+i)*3;
			*(TableauFloat+i) = *(TableauFloat+i)*3;
		};
	}
	printf("Valeurs finale tableau int: %d, %d, %d\n", TableauInt[0], TableauInt[1], TableauInt[2]);
	printf("Valeurs finale tableau float: %f, %f, %f\n", TableauFloat[0], TableauFloat[1], TableauFloat[2]);
	
}
	
