/*
01/10/21
TP2, ex 2.1

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that calculate a^b
*/
#include <stdio.h>

int puissance(int a, int b){
	int result = a;
	if (b == 0){
		result = 1;
	}
	else{
		for(int i=1; i<b; i++){
			result *= a;
		}
	}
	return result;
}

int main(){
	int a = 2, b = 5;
	printf("%d \n", puissance(a,b));
}
