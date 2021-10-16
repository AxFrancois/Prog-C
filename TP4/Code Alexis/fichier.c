/*
Nom du fichier : fichier.c
Auteur : Alexis PINCEMIN
Objectif : écrire et lire dans un fichier
*/

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(void)
{
    char message[] = "Ecriture et lecture dans un fichier";

    char fichier[] = "./monfichier.txt";

    ecrire_dans_fichier(fichier, message);
    
    lire_fichier(fichier);
    return 0;
}

/*on ouvre le fichier on lis sont contenu qu'on stock dans la variable content
et on affiche chaque caractère qu'elle contient*/
void lire_fichier(char *nom_de_fichier)
{
    char content[1000];
    int fd, count, size;
    fd = open (nom_de_fichier, O_RDONLY);
    size = read(fd, content, 1000);
    for (count = 0; count < size; count ++) {
    printf("%c", content[count]);
    }
    close(fd);
}
/*on ouvre le fichier et on écris le message passer en paramètre
grace à la fonction write*/
void ecrire_dans_fichier(char *nom_de_fichier, char *message)
{
    int fd, size;
    fd = open (nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}
