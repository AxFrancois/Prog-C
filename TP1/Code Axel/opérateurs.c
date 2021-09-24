#include <stdio.h>


int main(){
	int a = 16, b = 3;
	
	int somme = a+b;
	int soustraction = a-b;
	int produit = a*b;
	int division = a/b;
	int modulo = a%b;
	
	int inf = a < b;
	int infegal = a <= b;
	int sup = a > b;
	int supegal = a > b;
	int egal = a == b;
	int different = a != b;
	int neg = !a;
	int et = a && b;
	int ou = a || b;
	
	printf("a = %d, b = %d \n", a, b);	
	printf("somme %d \n",somme);
	printf("soustraction %d \n",soustraction);
	printf("produit %d \n",produit);
	printf("division %d \n",division);
	printf("modulo %d \n",modulo);
	printf("inf %d \n",inf);
	printf("infegal %d \n",infegal);
	printf("sup %d \n",sup);
	printf("supegal %d \n",supegal);
	printf("egal %d \n",egal);
	printf("different %d \n",different);
	printf("neg %d \n",neg);
	printf("et %d \n",et);
	printf("ou %d \n",ou);
}
