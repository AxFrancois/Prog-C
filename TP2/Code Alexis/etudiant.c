/*
Nom du fichier : etudiant.c
Auteur : Alexis PINCEMIN
Objectif : déclare, initialise et affiche les détails des cinq étudiants.es en utilisant des tableaux.
*/

#include <stdio.h> 

int main(){

	/*Décalration et initialisation des tableaux*/
	char prenom[5][30] = {"Jules","Jade","Alice","Lucas", "Louise"};
	char nom[5][30]= {"Uzumaki","Hatake","Aruno","Rock","Uchiwa"};
	char address[5][130] = {"122 Kennedi Mount Apt 20045", "20584 O'Conner Corner Apt. 765","41956 Rice Branch Apt. 950","5117 Rutherford Forest Apt. 583","51770 Reynolds Pines Suite 650"};
	int notes1[5] = {10,13,19,10,8};
	int notes2[5] = {6,8,17,11,15};

	/*affichage des informations de chaque étudiants.es */
	for(int i = 0; i< 5 ; i++){
		printf("etudiant numero %d { prenom : %s, nom : %s, addresse : %s, notes : %d, %d }\n",i+1,*(prenom+i),*(nom+i)
		,*(address+i),*(notes1+i),*(notes2+i));	
	}
return 0;
}



	


