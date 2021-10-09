/*
01/10/21
TP2, ex 2.5

@Author : Axel François
https://github.com/AxFrancois/Prog-C/

Program that create 5 students using arrays with the following fromat :
his name, first name, address, and notes in 2 modules (C programming, Operating system).
*/

#include <stdio.h>

int main(){
	char Etudiant1[5][100] = {"Axel", "François", "16 Rue du Lama, Pétaouchnok", "15", "15"};
	char Etudiant2[5][100] = {"Alexis", "Pincemin", "512 Baker Street, London", "16", "14"};
	char Etudiant3[5][100] = {"Matthieu", "Pettex", "12 Rue Sans-La-Fibre, Campgneland", "10", "12"};
	char Etudiant4[5][100] = {"Nathan", "Hutin", "28 Place du Sport, Décathlon", "12", "10"};
	char Etudiant5[5][100] = {"Leo", "Gouchon", "3 Rue des Arts, Paris", "13", "9"};
	printf("%s %s \nAdresse : %s \nNote de C : %s, Note OS : %s\n", Etudiant1[0],Etudiant1[1], Etudiant1[2],Etudiant1[3],Etudiant1[4]);
	printf("%s %s \nAdresse : %s \nNote de C : %s, Note OS : %s\n", Etudiant2[0],Etudiant2[1], Etudiant2[2],Etudiant2[3],Etudiant2[4]);
	printf("%s %s \nAdresse : %s \nNote de C : %s, Note OS : %s\n", Etudiant3[0],Etudiant3[1], Etudiant3[2],Etudiant3[3],Etudiant3[4]);
	printf("%s %s \nAdresse : %s \nNote de C : %s, Note OS : %s\n", Etudiant4[0],Etudiant4[1], Etudiant4[2],Etudiant4[3],Etudiant4[4]);
	printf("%s %s \nAdresse : %s \nNote de C : %s, Note OS : %s\n", Etudiant5[0],Etudiant5[1], Etudiant5[2],Etudiant5[3],Etudiant5[4]);
}
