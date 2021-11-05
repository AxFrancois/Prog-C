/*
15/10/21
TP4, ex 4.6

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


TO DO : GERER ESPACE + input nom fichierl
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int chercher_fichier(char *nom_de_fichier, char *word){
	char content[1000];
 	int fd, count, size;
	int ligne = 1;
	fd = open (nom_de_fichier, O_RDONLY);
	size = read(fd, content, 1000);
	int comtpage_mot = 0;
	for (count = 0; count < size; count ++) {
		//printf("%c", content[count]);
		if (content[count] == '\n' | count == size-1){
			if (comtpage_mot != 0){
				printf("Ligne %d, %d fois\n", ligne,comtpage_mot);
			}
			ligne += 1;
			comtpage_mot = 0;
		}
		for (int i = 0; i < strlen(word) & count+i <size; i ++) {		
			if (content[count+i] != word[i]){
				break;
			}
			else if (i == strlen(word)-1){
				comtpage_mot ++;			
			}
		}
	}
	close(fd);
};

int main(int argc, char ** argv){
	//printf("%s", argv[1]);
	chercher_fichier("./fichier.c",argv[1]);
	//chercher_fichier(argv[2],argv[1]);
}
