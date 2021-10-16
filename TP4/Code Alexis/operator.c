/*
Nom du fichier : operator.c
Auteur : Alexis PINCEMIN
Objectif : Manipuler les pointeurs de fonction
*/

#include <stdio.h>
#include "operator.h"


int main(void)
{
    
    int num1 = 10;
	int num2 = 45;
	char op = '*';
	/*pointeur de fonction*/
    int (*func)(int, int);

	/*pour chaque cas on attribut a func une fonction*/
	switch(op){
		case '*'  : func = produit;
			break;
		case '-' : func = difference;
			break;
		case '+' : func = somme;
			break;
		case '/' : func = quotient;
			break;
		case '%' : func = modulo;
			break;
		case '&' : func = et;
			break;
		case '|' : func = ou;
			break;
		case '~' : func = negation;
			break;
    }
	/*on appel func qui à été préalablement initialisé*/
    printf("Résultat: %d\n",func(num1, num2));
    return 0;

}
/*implémentation de chaque fonction définit préalablement dans operator.h*/
int somme(int num1, int num2)
{
    return num1 + num2;
}
int difference(int num1, int num2)
{
    return num1 - num2;
}
int produit(int num1, int num2)
{
    return num1 * num2;
}
int quotient(int num1, int num2)
{
    return num1 / num2;
}
int modulo(int num1, int num2)
{
    return num1 % num2;
}
int et(int num1, int num2)
{
    return num1 & num2;
}
int ou(int num1, int num2)
{
    return num1 | num2;
}
int negation(int num1, int num2)
{
    return ~num1;
}
