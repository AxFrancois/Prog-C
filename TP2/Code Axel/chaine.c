/*
01/10/21
TP2, ex 2.4

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that :
1. calculate the length of a string
2. copy a string into another
3. concatenates two strings
*/

#include <stdio.h>

int compteurCaracteres(char * mot){	//Function calculate the length of the string "mot"
	int i = 0;
	char sortie = 1;
	while (sortie !=0){
		sortie = mot[i];
		//printf("%c \n", sortie);
		i ++;
	}
	return i-1;
}

int CopyPasta(char * copied, char * pasted){	//Function copy the string "copied" into "pasted"
	int taille = compteurCaracteres(copied);
	for(int i = 0; i<taille; i++){
		pasted[i] = copied[i];
		//printf("%s", pasted);
	}
	printf("Nouvelle chaine %s \n",pasted);
}

int Concatenator(char * mot1, char * mot2){	//Function concatenates "mot1" and "mot2"
	int taille1 = compteurCaracteres(mot1);
	int taille2 = compteurCaracteres(mot2);
	int tailletotale = taille1 + taille2;
	char str[tailletotale];
	str[tailletotale] =0;
	printf("%c \n",str[tailletotale]);
	for(int i = 0; i<taille1; i++){
		str[i] = mot1[i];
		printf("%c \n", mot1[i]);
	}
	for(int i = taille1; i<tailletotale; i++){
		str[i] = mot2[i-taille1];
		printf("%c \n", mot2[i-taille1]);
	}
	printf("Concaténation : %s \n",str);
	printf("Nombre de caractères : %ld \n", sizeof(str));
}

int main(){
	char str1[] = "Patate";
	char str2[] = "Carotte";
	char str3[] = "Poireau";
	printf("Nombre de caractères : %d \n", compteurCaracteres(str1));
	CopyPasta(str1,str2);
	Concatenator(str1,str3);
}
