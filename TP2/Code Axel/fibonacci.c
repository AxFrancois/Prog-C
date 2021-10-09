/*
01/10/21
TP2, ex 2.3

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that calculate the Nth first terms of the Fibonacci sequence
*/
#include <stdio.h>

int main(){
	int n = 10;
	unsigned long long unmoins2 = 1;
	printf("U%d = %llu \n", 0,unmoins2);
	unsigned long long unmoins1 = 1;
	printf("U%d = %llu \n", 1,unmoins1);
	unsigned long long un;
	for(int i=2; i<=n; i++){
		un = unmoins1 + unmoins2;
		unmoins2 = unmoins1;
		unmoins1 = un;
		printf("U%d = %llu \n", i,un);
		
	}
}	
