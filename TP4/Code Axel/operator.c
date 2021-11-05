/*
15/10/21
TP4, ex 4.1

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that performs an arithmetic or logical operation between num1 and num2 depending on the value of op using functions
*/

#include <stdio.h>
#include <string.h>
#include "operator.h"

int somme(int num1, int num2){
	return num1 + num2;
}

int difference(int num1, int num2){
	return num1 - num2;
}

int produit(int num1, int num2){
	return num1 * num2;
}

int quotient(int num1, int num2){
	return num1 / num2;
}

int modulo(int num1, int num2){
	return num1 % num2;
}

int et(int num1, int num2){
	return num1 & num2;
}

int ou(int num1, int num2){
	return num1 | num2;
}

int negation(int num1){
	return ~num1;
}

int main(){
	int num1 = 100, num2 = 15;
	char op = '|';
	int signed result;
	switch(op){
		// +
		case '+' : result = somme(num1, num2);
		break;
		// -
		case '-' : result = difference(num1, num2);
		break;
		// *
		case '*' : result = produit(num1, num2);
		break;
		// /
		case '/' : result = quotient(num1, num2);
		break;
		// %
		case '%' : result = modulo(num1, num2);
		break;
		// &
		case '&' : result = et(num1, num2);
		break;
		// |
		case '|' : result = ou(num1, num2);
		break;
		// ~
		case '~' : result = negation(num1) ;
		break;
		default: result = -1;
	}
	printf("%d \n", result);
}

	
