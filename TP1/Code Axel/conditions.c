/*
24/09/21
TP1, ex 1.7

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that show numbers between 1 and 1000 that are divisible:
1. by 2 and 15
2. by 103 or 107
3. 7 or 5 but not 3
*/

#include <stdio.h>


int main(){
	for (int a = 1; a<=1000; a++) {
		int cond1 = 0, cond2 = 0, cond3 = 0;
		if (!(a % 2) && !(a % 15)) {
			printf("%d est divisible par 2 et 15. ", a);
			cond1 = 1;
		}
		if (!(a % 103) || !(a % 105)) {
			printf("%d est divisible par 103 ou 105. ", a);
			cond2 = 1;
		}
		if ((!(a % 7) || !(a % 5)) && (a % 3)) {
			printf("%d est divisible par 7 ou 5, mais pas par 3. ", a);
			cond3 = 1;
		}
		if (cond1 == 1 || cond2 == 1 || cond3 == 1){		
			printf("\n");}
	}
}
