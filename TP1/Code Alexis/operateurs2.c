#include <stdio.h>

int main(){

	int num1 = 20;
	int num2 = 45;
	char op = '&';
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
