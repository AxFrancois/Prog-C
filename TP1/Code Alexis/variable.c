/*
Nom du fichier : variable.c
Auteur : Alexis PINCEMIN
Objectif : affecter et afficher les valeurs des variables des différents types de base 
*/


#include <stdio.h>

int main(){

	char c = 'A';
	signed char sc = 'B';
	unsigned char uc = 'C';
	short s = 10;
	unsigned short us = 3;
	signed short ss = -10;
	int  i = 12 ;
	unsigned int ui = 45;
	signed int si = -5;
	long int li = 1000;
	signed long int sli = -200;
	unsigned long int uli = 600;
	long long int lli = 10000;
	signed long long int  slli = -2000;
	unsigned long long int ulli = 6000;
	float  f= 2.33;
	double d= 155.666;
	long double ld = 110000.22554;

	printf("%c \n" , c);
	printf("%hhu \n" , sc);
	printf("%hhu \n" , uc);
	printf("%hd \n" , s);
	printf("%hu \n" , us);
	printf("%d \n" , ss);
	printf("%d \n" , i);
	printf("%u \n" , ui);
	printf("%u \n" , si);
	printf("%ld \n" , li);
	printf("%ld \n" , sli);
	printf("%lu \n" , uli);
	printf("%lld \n" , lli);
	printf("%lld \n" , slli);
	printf("%llu \n" , ulli);
	printf("%f \n" , f);
	printf("%g \n" , d);
	printf("%Lg \n" , ld);


	return 0;
}