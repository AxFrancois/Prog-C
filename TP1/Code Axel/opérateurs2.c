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

	
