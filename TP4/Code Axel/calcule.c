/*
15/10/21
TP4, ex 4.4

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	int num1 = atoi(argv[2]), num2 = atoi(argv[3]);
	char op = argv[1][0];
	int signed result;
	switch(op){
		// +
		case '+' : result = num1 + num2;
		break;
		// -
		case '-' : result = num1 - num2;
		break;
		// *
		case '*' : result = num1 * num2;
		break;
		// /
		case '/' : result = num1 / num2;
		break;
		// %
		case '%' : result = num1 % num2;
		break;
		// &
		case '&' : result = num1 & num2;
		break;
		// |
		case '|' : result = num1 | num2;
		break;
		// ~
		case '~' : result = ~num1 ;
		break;
		default: result = -1;
	}
	printf("%d \n", result);
}
