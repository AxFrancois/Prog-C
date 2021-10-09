/*
Nom du fichier : operateurs2.c
Auteur : Alexis PINCEMIN
Objectif : effectuer des opérations définis par op sur num1 et num2 en utilisant switch case
*/

#include <stdio.h>

int main(){

	int num1 = 20;
	int num2 = 45;
	char op = '&';
    /*conversion char en int (code ASCII)*/
	int intOp = (int)op;
	int resultat;

	switch(op){
		case 42  : resultat = num1*num2;
			break;
		case 45 : resultat = num1-num2;
			break;
		case 43 : resultat = num1+num2;
			break;
		case 47 : resultat = num1/num2;
			break;
		case 37 : resultat = num1%num2;
			break;
		case 38 : resultat = num1&num2;
			break;
		case 124 : resultat = num1|num2;
			break;
		case 126 : resultat = ~num2;
			break;
    }
printf("%d \n", resultat);
return 0;
}