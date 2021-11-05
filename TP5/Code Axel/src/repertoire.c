/*
22/10/21
TP4, ex 5.1

@Author : Axel François
https://github.com/AxFrancois/Prog-C/


*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "repertoire.h"

void lire_dossier(char *directory){
	DIR *dirp = opendir(directory);
	if (dirp == NULL){
		perror("opendir");
	}
	else{
		chdir(directory);	
		struct dirent *ent;
		while(ent = readdir(dirp)){
			if (strcmp(ent->d_name, ".") & strcmp(ent->d_name, "..")){
				printf("%s\n", ent->d_name);			
			}			
		}		
	}
}

void lire_dossier_recursif(char *directory, int depth){
	DIR *dirp = opendir(directory);
	if (dirp != NULL){
		chdir(directory);
		struct dirent *ent;
		while(ent = readdir(dirp)){
			if (strcmp(ent->d_name, ".") & strcmp(ent->d_name, "..")){
				for(int i = 0; i<depth; i++){
					printf("\t");
				}
				printf("%s\n", ent->d_name);
				if (ent->d_type == DT_DIR){
					depth++;
					lire_dossier_recursif(ent->d_name, depth);
					printf("\n");
					chdir("..");
					depth--;
				}
			}
		}		
	}
}

void lire_dossier_iteratif(char *directory){
	DIR *dirp = opendir(directory);
	if (dirp != NULL){
		chdir(directory);
		struct dirent *ent;
		while(ent = readdir(dirp)){
			if (strcmp(ent->d_name, ".") & strcmp(ent->d_name, "..")){
				printf("%s\n", ent->d_name);
				if (ent->d_type == DT_DIR){
					DIR *dirp2 = opendir(ent->d_name);
					struct dirent *ent2;
					while(ent2 = readdir(dirp2)){
						if (strcmp(ent2->d_name, ".") & strcmp(ent2->d_name, "..")){
							printf("	%s\n", ent2->d_name);
						}
					}
				}
			}
		}	
	}
}


int main(int argc, char ** argv){
	//lire_dossier(argv[1]);
	//lire_dossier_recursif(argv[1] ,0);
	lire_dossier_iteratif(argv[1]);
}
