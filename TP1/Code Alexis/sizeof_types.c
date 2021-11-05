/*
Nom du fichier : sizeof_types.c
Auteur : Alexis PINCEMIN
Objectif : afficher la taille des différents types de base (en octets)
*/


#include <stdio.h>
#include <limits.h>

int main(){

	printf("char : %ld \n", sizeof(char));
	printf("signed char : %ld \n", sizeof(signed char));
	printf("unsigned char : %ld \n", sizeof(unsigned char));
	printf("short : %ld \n", sizeof(short));
	printf("signed short : %ld \n", sizeof(signed short));
	printf("unsigned short : %ld\n", sizeof(unsigned short));
	printf("int : %ld \n", sizeof(int));
	printf("signed int : %ld \n", sizeof(signed int));
	printf("unsigned int : %ld \n", sizeof(unsigned int));
	printf("long int : %ld \n", sizeof(long int));
	printf("signed long int : %ld \n", sizeof(signed long int));
	printf("unsigned long int : %ld \n", sizeof(unsigned long int));
	printf("long long int : %ld \n", sizeof(long long int));
	printf("unsigned long long int : %ld \n", sizeof(unsigned long long int));
	printf("signed long long int : %ld \n", sizeof(signed long long int));
	printf("float : %ld \n", sizeof(float));
	printf("double : %ld \n", sizeof(double));
	printf("long double : %ld \n", sizeof(long double));

	return 0;
	
}



