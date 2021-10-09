/*
Nom du fichier : binaireV2.c
Auteur : Alexis PINCEMIN
Objectif : afficher un nombre décimal en binaire
*/

#include <stdio.h>  

#define MAX_SIZE 20

int main(){
  
  int nombre, mask, arrayBinaire[MAX_SIZE], bits, size_opt, decrement;  
  
  printf("nombre à convertir: ");  
  scanf("%d",&nombre);  
  
  mask = 1;
/*
Boucle for qui permet de comparer le nombre entré avec un masque
qui sera décalé vers la gauche à chaque itération et ainsi récupérer
le resultat qui est mis dans le tableau arrayBinaire
*/
for(int i = 0; i < MAX_SIZE; i++){
  bits = (nombre & mask) ?  1 : 0;
  arrayBinaire[i] = bits;
  mask<<=1;
}

size_opt = MAX_SIZE-1;
decrement = MAX_SIZE-1;


/*
Boucle do while qui permet d'ajuster la taille du tableau à afficher
*/
while(arrayBinaire[decrement] == 0){
      size_opt -= 1;
      decrement--;
}


/*
Boucle for qui permet d'afficher le tableau
en commencant par le dernier élément
*/
printf("La valeur binaire de %d est : ", nombre);
for(int i = size_opt; i >= 0; i--){
  printf("%d", arrayBinaire[i]);
  if(i == 0){printf("\n");}
}
  return 0;
}