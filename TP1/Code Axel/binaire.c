/*
24/09/21
TP1, ex 1.9

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that print a decimal value in binary
*/

#include <stdio.h>

int main(){
	int nombre = 65535; //0 4096 65536 65535 1024
	
	int binarray[30], i;
	if (nombre == 0){
		printf("0");
	}
	for (i = 0; nombre > 0; i++) {
		binarray[i] = nombre%2;
		nombre /= 2;
	}
	for (i -= 1; i >= 0; i--){
		printf("%d", binarray[i]);
	}
	printf("\n");
}
