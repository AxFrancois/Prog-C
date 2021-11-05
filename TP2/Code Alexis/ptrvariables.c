/*
Nom du fichier : ptrvariables.c
Auteur : Alexis PINCEMIN
Objectif : affecte et affiche les valeurs des variables de différents types de base en utilisant leurs adresses
*/

#include <stdio.h>

int main(){

	/*déclaration et initalisation des variables et de leurs pointeurs*/

	char c = 'A';
	char *ptrc = &c;

	signed char sc = 'B';
	signed char *ptrsc = &sc;

	unsigned char uc = 'C';
	unsigned char *ptruc = &uc;

	short s = 10;
	short *ptrs = &s;

	unsigned short us = 3;
	unsigned short *ptrus = &us;

	signed short ss = -10;
	signed short *ptrss = &ss;

	int  i = 12 ;
	int *ptri = &i;

	unsigned int ui = 45;
	unsigned int *ptrui = &ui;

	signed int si = -5;
	signed int *ptrsi = &si;

	long int li = 1000;
	long int *ptrli = &li;

	signed long int sli = -200;
	signed long int *ptrsli = &sli;

	unsigned long int uli = 600;
	unsigned long int *ptruli = &uli;

	long long int lli = 10000;
	long long int *ptrlli = &lli;

	signed long long int  slli = -2000;
	signed long long int *ptrslli = &slli;

	unsigned long long int ulli = 6000;
	unsigned long long int *ptrulli = &ulli;

	float  f= 2.33;
	float *ptrf = &f;

	double d= 155.666;
	double *ptrd = &d;

	long double ld = 110000.22554;
	long double *ptrld = &ld;

	/*affichage des valeurs des variables et de leurs addresses*/

	printf("valeur : %c, addresse : %p \n" , *ptrc,ptrc );
	printf("valeur : %hhu, addresse : %p  \n" , *ptrsc, ptrsc);
	printf("valeur : %hhu, addresse : %p \n" , *ptruc,ptruc);
	printf("valeur : %hd, addresse : %p \n" , *ptrs,ptrs);
	printf("valeur : %hu, addresse : %p \n" , *ptrus,ptrus);
	printf("valeur : %d, addresse : %p \n" , *ptrss,ptrss);
	printf("valeur : %d, addresse : %p \n" , *ptri,ptri);
	printf("valeur : %u, addresse : %p \n" , *ptrui,ptrui);
	printf("valeur : %u, addresse : %p \n" , *ptrsi,ptrsi);
	printf("valeur : %ld, addresse : %p \n" , *ptrli,ptrli);
	printf("valeur : %ld, addresse : %p \n" , *ptrsli,ptrsli);
	printf("valeur : %lu, addresse : %p \n" , *ptruli,ptruli);
	printf("valeur : %lld, addresse : %p \n" , *ptrlli,ptrlli);
	printf("valeur : %lld, addresse : %p \n" , *ptrslli,ptrslli);
	printf("valeur : %llu, addresse : %p \n" , *ptrulli,ptrulli);
	printf("valeur : %f, addresse : %p \n" , *ptrf,ptrf);
	printf("valeur : %g, addresse : %p \n" , *ptrd,ptrd);
	printf("valeur : %Lg, addresse : %p \n" , *ptrld,ptrld);


	return 0;
}
