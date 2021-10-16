/*
Nom du fichier : etudiant_bd.c
Auteur : Alexis PINCEMIN
Objectif : écrire dans un fichier les informations de 5 étudiants
*/

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define NOMBRE_ETUDIANTS 2


int main(void)
{


	 typedef struct etudiant{
		char prenom[30];
		char nom[30];
		char address[135];
		char notes1[3];
		char notes2[3];
	}etudiant;

	etudiant groupeEtudiants[NOMBRE_ETUDIANTS];
	
    char fichier[] = "./etudiant.txt";
    char donnee[135];

	for(int i = 0; i< NOMBRE_ETUDIANTS; i++){
	strcpy(groupeEtudiants[i].nom, "");
	strcpy(groupeEtudiants[i].prenom, "");
	strcpy(groupeEtudiants[i].address,"");
	strcpy(groupeEtudiants[i].notes1,"");
	strcpy(groupeEtudiants[i].notes2,"");
	}


    for(int i = 0 ; i < NOMBRE_ETUDIANTS; i++)
    {
        printf("Prenom : ");
        scanf("%30s[^\n]",groupeEtudiants[i].prenom);
        ecrire_dans_fichier(fichier, groupeEtudiants[i].prenom);

        printf("Nom : ");
        scanf("%30s[^\n]",groupeEtudiants[i].nom);
        ecrire_dans_fichier(fichier, groupeEtudiants[i].nom);

        printf("Adresse : ");
        scanf("%30s[^\n]",groupeEtudiants[i].address);
        ecrire_dans_fichier(fichier, groupeEtudiants[i].address);


        printf("1er note : ");
        scanf("%30s[^\n]",groupeEtudiants[i].notes1);
        ecrire_dans_fichier(fichier, groupeEtudiants[i].notes1);

        printf("2eme note : ");
        scanf("%30s[^\n]",groupeEtudiants[i].notes2);
		int fd;
		fd = open(fichier,O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
		write(fd,("%s ",groupeEtudiants[i].notes2), strlen(groupeEtudiants[i].notes2));
		close(fd);
        
    }

    return 0;
}


void ecrire_dans_fichier(char *nom_de_fichier, char *message)
{
    int fd, size;
    fd = open (nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
	size = write(fd, ", ", 2);
    close(fd);
}
