/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#include "client.h"

/* 
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd) {
 
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}


int envoie_operateur_numeros(int socketfd) {
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre calcul format {op} {num1} {num2} (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "calcule: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Resultat recu: %s\n", data);
 
  return 0;
}


int lire_fichier(char *nom_de_fichier, int index, int *TableNote){
	char content[10];
 	int fd, size, note;
	fd = open (nom_de_fichier, O_RDONLY);
	size = read(fd, content, 1000);
	note = atoi(content);
	close(fd);
  TableNote[index] = note;
};

void lire_dossier_recursif(char *directory, int callCount, int *TableNote, int *TableEtudiant){
	DIR *dirp = opendir(directory);
	if (dirp != NULL){
		chdir(directory);
		struct dirent *ent;
		while(ent = readdir(dirp)){
			if (strcmp(ent->d_name, ".") & strcmp(ent->d_name, "..")){
				if (ent->d_type == DT_DIR){
          TableEtudiant[callCount/5] = atoi(ent->d_name);
					lire_dossier_recursif(ent->d_name, callCount, TableNote, TableEtudiant);
          callCount = callCount+5;
					chdir("..");
				}
        else{
          lire_fichier(ent->d_name, callCount, TableNote);
          callCount++;
        }
			}
		}		
	}
}


int Calcul(int socketfd, int nb1, int nb2, char op) {
  char data[1024];
  memset(data, 0, sizeof(data));

  char num1[10],num2[10];
  char opStr[2];
  opStr[0] = op;
  opStr[1] = '\0';
  sprintf(num1, "%d", nb1);
  sprintf(num2, "%d", nb2);

  char message[100]; 
  strcpy(data, "calcule: ");
  strcat(data, opStr);
  strcat(data, " \0");
  strcat(data, num1);
  strcat(data, " \0");
  strcat(data, num2);
  
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  //printf("Resultat recu: %s\n", data);
 
  //printf("%d\n", atoi(data));
  return atoi(data);
}


int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  //envoie_recois_message(socketfd);

  // fct calcul au serveur
  //envoie_operateur_numeros(socketfd);
	
  
  char path[50] = "../etudiant";
  int nbEtudiant = 5;
  int TableNote[25] = {};
  int TableEtudiant[5] = {};
  int callCount = 0;
  lire_dossier_recursif(path, callCount, TableNote, TableEtudiant);
  for(int i = 0;i<5;i++){
    printf("Nom Etu %d\n", TableEtudiant[i]);
    int nbCalcul = TableNote[i*5];
    for(int j = 1;j<5;j++){
      //printf("%d\n", TableNote[i*5+j]);
      nbCalcul = Calcul(socketfd,nbCalcul,TableNote[i*5+j],'+');
    }
    nbCalcul = Calcul(socketfd,nbCalcul,5,'/');
    printf("Moyenne : %d\n", nbCalcul);
  }
  Calcul(socketfd,0,0,'0');
  

  close(socketfd);
}
