/*
15/10/21
TP4, ex 4.2

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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
	char message[] = "Message : \nOUI ALLO \n";
	char nom_de_fichier[] = "./fichiertexte.txt";
	ecrire_dans_fichier(nom_de_fichier, message);
	lire_fichier(nom_de_fichier);
}
