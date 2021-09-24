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
