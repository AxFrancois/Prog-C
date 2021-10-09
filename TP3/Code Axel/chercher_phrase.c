/*
08/10/21
TP3, ex 3.7

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that search if a certain string is present in a table of 10 strings (without using any libraries)
*/

#include <stdio.h>

int compteurCaracteres(char * mot){
	int i = 0;
	char sortie = 1;
	while (sortie !=0){
		sortie = mot[i];
		//printf("%c \n", sortie);
		i ++;
	}
	return i-1;
}

int main(){
	int tablesize = 10;
	char table[10][200] = {"Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
			      	"Vivamus ullamcorper purus ut quam interdum vulputate.",
				"Sed eu mauris laoreet ligula ultrices ultrices et non turpis.",
				"Ut eget nisl at libero tincidunt facilisis vitae nec magna.",
				"Phasellus at justo eu elit venenatis fringilla vel euismod libero.",
				"Nullam non turpis eget enim vestibulum dictum a id leo.",
				"Nullam ut dui ultrices, sagittis erat vitae, varius mauris.",
				"Praesent dapibus arcu ut semper semper.",
				"Nunc sagittis ante luctus nibh tempor consequat.",
				"Nunc consectetur justo nec sapien gravida lobortis."};

	char *phraseAChercher = "Nunc consectetur justo nec sapien gravida lobortis.";
	int HasFound = 0;
	for(int i=0; i<tablesize; i++){
		for(int j = 0; table[i][j] == phraseAChercher[j] && table[i][j] != '\0' && phraseAChercher[j] != '\0'; j++){
			if (j == compteurCaracteres(phraseAChercher)-1){
				HasFound = 1;
			}
		}
	}

	//Affichage du résultat
	if (HasFound == 1){
		printf("Phrase présente \n");
	}
	else{
		printf("Phrase absente \n");
	}				
}
