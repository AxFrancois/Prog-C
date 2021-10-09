/*
24/09/21
TP1, ex 1.8

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that performs an arithmetic or logical operation between num1 and num2 depending on the value of op
*/

#include <stdio.h>
#include <string.h>

int main(){
	int num1 = 100, num2 = 15;
	char op = '%';
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

	
