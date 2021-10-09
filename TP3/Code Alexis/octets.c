/*
Nom du fichier : octets.c
Auteur : Alexis PINCEMIN
Objectif :  utiliser char et les opérateurs de pointeurs pour voir les octets d'une variable short, int, long int, float, double et long double.

*/

#include <stdio.h>

int main(){
	
	short a = 45;
	int b = 5448;
	long int c = 9852654;
	float d  = 54.25;
	double e = 65465.36545;
	long double f = 445747785.6544899;

	/*on définis un pointeur nul*/
	unsigned char *aptr =NULL;
	/*on donne à ce pointeur l'addresse de notre variable et conversion*/
    aptr = (unsigned char*)&a;
	
	for(int i = 0 ; i < sizeof(a); i++)
		printf("%x ", *(aptr+i));
printf("\n");

	unsigned char *bptr =NULL;
    bptr = (unsigned char*)&b;
	
	for(int i = 0 ; i < sizeof(b); i++)
		printf("%x ", *(bptr+i));
printf("\n");

	unsigned char *cptr =NULL;
    cptr = (unsigned char*)&c;
	
	for(int i = 0 ; i < sizeof(c); i++)
		printf("%x ", *(cptr+i));

printf("\n");

	unsigned char *dptr =NULL;
    dptr = (unsigned char*)&d;
	
	for(int i = 0 ; i < sizeof(d); i++)
		printf("%x ", *(dptr+i));

printf("\n");

	unsigned char *eptr =NULL;
	eptr = (unsigned char*)&e;
		
	for(int i = 0 ; i < sizeof(e); i++)
		printf("%x ", *(eptr+i));

printf("\n");
	unsigned char *fptr =NULL;
	fptr = (unsigned char*)&f;
		
	for(int i = 0 ; i < sizeof(f); i++)
		printf("%x ", *(fptr+i));
printf("\n");

return 0;
}

