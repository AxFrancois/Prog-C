/*
01/10/21
TP2, ex 2.6

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create 5 students using struct with the following fromat :
his name, first name, address, and notes in 2 modules (C programming, Operating system).
*/

#include <stdio.h>
#include <string.h>

int main(){
	struct etudiant{
		char prenom[30];
		char nom[30];
		struct adresse{
		char rue[50];
		char ville[40];
		} adresse;
		short NoteC;
		short NoteOS;
	};
	int nombreEtudiant = 5;
	struct etudiant etudiantGroupeD[nombreEtudiant];
	
	strcpy(etudiantGroupeD[0].prenom, "Axel");
	strcpy(etudiantGroupeD[0].nom, "François");
	strcpy(etudiantGroupeD[0].adresse.rue, "16 Rue du Lama");
	strcpy(etudiantGroupeD[0].adresse.ville, "Pétaouchnok");
	etudiantGroupeD[0].NoteC = 15;
	etudiantGroupeD[0].NoteOS = 15;

	strcpy(etudiantGroupeD[1].prenom, "Alexis");
	strcpy(etudiantGroupeD[1].nom, "Pincemin");
	strcpy(etudiantGroupeD[1].adresse.rue, "512 Baker Street");
	strcpy(etudiantGroupeD[1].adresse.ville, "London");
	etudiantGroupeD[1].NoteC = 16;
	etudiantGroupeD[1].NoteOS = 14;

	strcpy(etudiantGroupeD[2].prenom, "Matthieu");
	strcpy(etudiantGroupeD[2].nom, "Pettex");
	strcpy(etudiantGroupeD[2].adresse.rue, "12 Rue Sans-La-Fibre");
	strcpy(etudiantGroupeD[2].adresse.ville, "Campgneland");
	etudiantGroupeD[2].NoteC = 10;
	etudiantGroupeD[2].NoteOS = 12;

	strcpy(etudiantGroupeD[3].prenom, "Nathan");
	strcpy(etudiantGroupeD[3].nom, "Hutin");
	strcpy(etudiantGroupeD[3].adresse.rue, "28 Place du Sport");
	strcpy(etudiantGroupeD[3].adresse.ville, "Décathlon");
	etudiantGroupeD[3].NoteC = 12;
	etudiantGroupeD[3].NoteOS = 10;

	strcpy(etudiantGroupeD[4].prenom, "Leo");
	strcpy(etudiantGroupeD[4].nom, "Gouchon");
	strcpy(etudiantGroupeD[4].adresse.rue, "3 Rue des Arts");
	strcpy(etudiantGroupeD[4].adresse.ville, "Paris");
	etudiantGroupeD[4].NoteC = 13;
	etudiantGroupeD[4].NoteOS = 9;
	
	for(int i=0; i<nombreEtudiant; i++){
		printf("%s %s \nAdresse : %s, %s \nNote de C : %d, Note OS : %d\n", etudiantGroupeD[i].prenom, etudiantGroupeD[i].nom, etudiantGroupeD[i].adresse.rue, etudiantGroupeD[i].adresse.ville, etudiantGroupeD[i].NoteC, etudiantGroupeD[i].NoteOS);
	}
	
}
	
