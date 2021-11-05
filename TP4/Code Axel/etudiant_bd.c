/*
15/10/21 -> 05/11/21
TP4, ex 4.3

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Build Student Database
*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "fichier.h"

int lire_fichier(char *nom_de_fichier){
	char content[1000];
 	int fd, count, size;
	fd = open (nom_de_fichier, O_RDONLY);
	size = read(fd, content, 1000);
	for (count = 0; count < size; count ++) {
		printf("%c", content[count]); 
	}
	close(fd);
};

int ecrire_dans_fichier(char *nom_de_fichier, char *message){
	int fd, count, size;
	fd = open (nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
	size = write(fd, message, strlen(message));
	close(fd);
};


int main(){
	int nombreEtudiant = 5;
	char nom_de_fichier[] = "./etudiant.txt";
	remove(nom_de_fichier);
	for(int etudiantIndex=0; etudiantIndex<nombreEtudiant; etudiantIndex++){
		// LA SAISIE DE CARACTERE C'EST INFAME

		char Line[1024];
		memset(Line,0,sizeof(Line));
		char LineBuilder[256];		
		memset(LineBuilder,0,sizeof(LineBuilder));
		
		//Prenom
		printf("Prenom : ");
		//scanf("%s", &temp); //but fail to capturate " " (space) <--- 1h and half wasted :)
		fgets(LineBuilder,50,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0'; //<-- probably unorthodox way to get rid on the '\n'
		strcat(Line,LineBuilder);
		
		strcat(Line,"; ");

		//Nom
		memset(LineBuilder,0,sizeof(LineBuilder));
		printf("Nom : ");
		fgets(LineBuilder,50,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0';
		strcat(Line,LineBuilder);

		strcat(Line,"; Adresse : ");

		//Adresse Rue
		memset(LineBuilder,0,sizeof(LineBuilder));
		printf("Rue : ");
		fgets(LineBuilder,50,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0';
		strcat(Line,LineBuilder);

		strcat(Line,", ");

		//Adresse Ville
		memset(LineBuilder,0,sizeof(LineBuilder));
		printf("Ville : ");
		fgets(LineBuilder,50,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0';
		strcat(Line,LineBuilder);

		strcat(Line,"; Note de C : ");

		//Note C
		memset(LineBuilder,0,sizeof(LineBuilder));
		printf("Note de C : ");
		fgets(LineBuilder,5,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0';
		strcat(Line,LineBuilder);

		strcat(Line,"; Note de OS : ");

		//Note OS
		memset(LineBuilder,0,sizeof(LineBuilder));
		printf("Note OS : ");
		fgets(LineBuilder,5,stdin);
		LineBuilder[strlen(LineBuilder)-1] = '\0';
		strcat(Line,LineBuilder);

		strcat(Line,"\n");

		//printf("%s",Line);

		ecrire_dans_fichier(nom_de_fichier, Line);

	}
}

























	
