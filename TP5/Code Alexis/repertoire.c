/*
Nom du fichier : repertoire.c
Auteur : Alexis PINCEMIN
Objectif : manipuler les repertoires
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "repertoire.h"


int main(int argc, char *argv[])
{
    lire_dossier_iteratif(argv[1]);
    return 0;
}

void lire_dossier(char *folder)
{
    //on ouvre le dossier
    DIR *dir = opendir(folder);
    //gestion d'erreur
    if (dir == NULL) 
    {
        perror("opendir");
    }
    struct dirent * ent;
    //tant qu'il ya des fichier on affiche leurs noms
    while(ent = readdir(dir))
    {
        printf ("%s  ", ent->d_name);
    }
}

void lire_dossier_recursif(char *folder)
{
    //on ouvre le dossier
    DIR *dir = opendir(folder);
    if (dir == NULL) 
    {
        perror("opendir");
    }
    chdir(folder);
    struct dirent *ent;

    while(ent = readdir(dir))
    {
        //on vérifie que les dossiers ne soit pas . ou ..
        if(strcmp(".",ent->d_name) && strcmp("..",ent->d_name))
        {
            //on affiche ./ devant chaque nom de dossier
            if (ent->d_type == DT_DIR)
            {
                printf("./");
            }
            //on affiche leurs noms
            printf ("%s", ent->d_name);
            putchar('\n'); 
        }
        //si c'est un dossier et si ça n'est pas . ou .. alors on parcours ce dossier
        if (ent->d_type == DT_DIR && strcmp(".",ent->d_name) && strcmp("..",ent->d_name) ){
            lire_dossier_recursif(ent->d_name);  
            //on retourne au dossier parent
            chdir("..");
        }
    }
    putchar('\n'); 
}

void lire_dossier_iteratif(char *folder)
{
    DIR *dir = opendir(folder);
    if (dir == NULL) 
    {
        perror("opendir");
    }
    chdir(folder);
    struct dirent *ent;

     while(ent = readdir(dir))
    {
        if(strcmp(".",ent->d_name) && strcmp("..",ent->d_name))
        {
            if (ent->d_type == DT_DIR)
            {
                printf("./");
            }
            printf ("%s", ent->d_name);
            putchar('\n'); 
        }
        if (ent->d_type == DT_DIR && strcmp(".",ent->d_name) && strcmp("..",ent->d_name) ){
            //si c'est un dossier alors on re effectue la boucle pour se dossier
            DIR *dir = opendir(ent->d_name);
            if (dir == NULL) 
            {
                perror("opendir");
            }
            chdir(ent->d_name);
            struct dirent *ent;
            while(ent = readdir(dir))
            {
                if(strcmp(".",ent->d_name) && strcmp("..",ent->d_name))
                {
                    if (ent->d_type == DT_DIR)
                    {
                        printf("./");
                    }
                    printf ("%s", ent->d_name);
                    putchar('\n'); 
                }
            }
            putchar('\n'); 
            chdir("..");
        }
    }
}