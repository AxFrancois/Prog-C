/*
Nom du fichier : chercherfichier.c
Auteur : Alexis PINCEMIN
Objectif : rechercher une phrase dans un fichier
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    // char phraseRechercher[] = *argv[1];
    // char fichier[] = *argv[2];


    char phraseRecherche[] = "Bonjour";
    int sizePhraseRecherche = strlen(phraseRecherche);
    char fichier[]  ="./fichier_test.txt";


    FILE *fic=fopen("fichier_test.txt","r");
    
    if (fic==NULL)
        exit(1);
    
    int rows = 0;
    int count;
    char contentRows[500];

	/*on parcours chaque ligne*/
    while(fgets(contentRows, sizeof(contentRows), fic) != NULL){
        ++rows;
        count = 0;
		/*on parcours le contenu de la ligne a partir de l'élément i*/
        for(int i =0; i<strlen(contentRows);i++)
        {
            int equalsChar = 0;
	 		/*on parcours chaque élément de la phrase recherche*/
            for(int j = 0; j<sizePhraseRecherche; j++)
            {
				/*on compare la phrase avec les i+1ème élément*/
                if(phraseRecherche[j] == contentRows[i+j] )
                {
                    ++equalsChar;
                }
                if(equalsChar == sizePhraseRecherche)
                {
                    equalsChar = 0;
                    ++count;
                }
            }
        }
		/*si on a trouvé des mots en commun alors on affiche*/
        if(count != 0)
        {
                printf("Ligne %d : %d fois \n", rows, count);
        }
    }
    return 0;
}

