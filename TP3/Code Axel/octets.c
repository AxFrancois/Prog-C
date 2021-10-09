/*
08/10/21
TP3, ex 3.6

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create values with different data type and show the value of their bits
*/

#include <stdio.h>

int main(){
	short a = 30000;
	int b = 110000000;
	long int c = 111112147483001;
	float d = 99.92879337;
	double e = 9.872987943;
	long double f = 992979729.939879;

	unsigned char *sptr = NULL;
	sptr = (unsigned char *)&a;	//unsigned char ou %hhx https://stackoverflow.com/questions/8060170/printing-hexadecimal-characters-in-c, %02x permet d'afficher au moins 2 charactères
	printf("Octets d'un short (en héxa) : ");
	for(int i=sizeof(a)-1; i>-1; i--){
		printf("%02x ", *(sptr+i)); 
	}
	printf("\n");

	unsigned char *iptr = NULL;
	iptr = (unsigned char *)&b;
	printf("Octets d'un int (en héxa) : ");
	for(int i=sizeof(b)-1; i>-1; i--){
		printf("%02x ", *(iptr+i)); 
	}
	printf("\n");

	unsigned char *liptr = NULL;
	liptr = (unsigned char *)&c;
	printf("Octets d'un long int (en héxa) : ");
	for(int i=sizeof(c)-1; i>-1; i--){
		printf("%02x ", *(liptr+i));
	}
	printf("\n");

	unsigned char *fptr = NULL;
	fptr = (unsigned char *)&d;
	printf("Octets d'un float (en héxa) : ");
	for(int i=sizeof(d)-1; i>-1; i--){
		printf("%02x ", *(fptr+i));
	}
	printf("\n");

	unsigned char *dptr = NULL;
	dptr = (unsigned char *)&e;
	printf("Octets d'un double (en héxa) : ");
	for(int i=sizeof(e)-1; i>-1; i--){
		printf("%02x ", *(dptr+i));
	}
	printf("\n");

	unsigned char *ldptr = NULL;
	ldptr = (unsigned char *)&f;
	printf("Octets d'un long double (en héxa) : ");
	for(int i=sizeof(f)-1; i>-1; i--){
		printf("%02x ", *(ldptr+i));
	}
	printf("\n");
}
