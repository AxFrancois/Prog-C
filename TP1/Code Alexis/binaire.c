#include <stdio.h>

int main(){

	int nombre, i, binaireArray[100];


	printf("Entrez un nombre décimal : ");
	scanf("%d", &nombre);
	int nombreInit = nombre;

	for(i = 0; nombre > 0; i++){
		binaireArray[i] = nombre%2;
		nombre  /= 2;
}
		printf("\n");
		printf("La valeur binaire de %d est : ", nombreInit);

	for(i-=1; i>=0;i--){
		if(i == 0){printf("%d \n", binaireArray[i]);}
		printf("%d", binaireArray[i]);
}
return 0;
}
