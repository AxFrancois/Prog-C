/*
15/10/21
TP4, ex 4.5

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


*/

#include <stdio.h>

int factorielle (int num) {
  if (num == 0) {
    return 1;
  }
  else {
    return (num * factorielle (num-1));
  }
}

int main(){
	int resultat;
	int nombre = 10;
	resultat = factorielle(nombre);
		
	printf("Factorielle %d = %d\n", nombre, resultat);
	
}
