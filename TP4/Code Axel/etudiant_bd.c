/*
15/10/21
TP4, ex 4.3

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


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
		char prenom[50] = "Axel";
		char nom[50] = "François";
		char rue[50] = "16 Rue du Lama";
		char ville[50] = "Pétaouchnok";
		char noteC[50] = "15";
		char noteOS[50] ="15";
		
		// LA SAISIE DE CARACTERE C'EST INFAME, scanf ne récup pas les espace, et fgets complétement pété ne capture rien

		/*char temp;		
		
		
		printf("Prenom : ");
		scanf("%s", &temp); //but fail to capturate " " (space) <--- 1h and half wasted :)
		fgets(prenom,24,stdin);
		
		printf("Nom : ");
		scanf("%24[^\n]", nom);
		//fgets(nom,24,stdin);
	
		printf("Rue : ");
		scanf("%49[^\n]", rue);
		//fgets(rue,49,stdin);

		printf("Ville : ");
		scanf("%c", &temp);
		//fgets(ville,49,stdin);

		printf("Note de C : ");
		scanf("%c", &temp);
		//fgets(noteC,2,stdin);

		printf("Note OS : ");
		scanf("%c", &temp);
		//fgets(noteOS,2,stdin);

		*/


		ecrire_dans_fichier(nom_de_fichier, prenom);
		ecrire_dans_fichier(nom_de_fichier, nom);
		ecrire_dans_fichier(nom_de_fichier, "; Adresse : ");
		ecrire_dans_fichier(nom_de_fichier, rue);
		ecrire_dans_fichier(nom_de_fichier, ", ");
		ecrire_dans_fichier(nom_de_fichier, ville);
		ecrire_dans_fichier(nom_de_fichier, "; Note de C : ");
		ecrire_dans_fichier(nom_de_fichier, noteC);
		ecrire_dans_fichier(nom_de_fichier, "; Note de OS : ");
		ecrire_dans_fichier(nom_de_fichier, noteOS);
		ecrire_dans_fichier(nom_de_fichier, "\n");
		
	}
}

























	
