/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * ./client ./images/800px-2006-10-18Dahlia03m.bmp
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "bmp.h"

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
  
  strcpy(data,StringToJSON(data));

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

  strcpy(data,JsonToString(data));

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

  strcpy(data,JsonToString(data));
  printf("Resultat recu: %s\n", data);
 
  return 0;
}

void analyse(char *pathname, char *data) {
  //compte de couleurs
  couleur_compteur *cc = analyse_bmp_image(pathname);

  int nombre = 0;
  while ((0<nombre && nombre<=30) == 0){
    printf("Nombre de couleur (entre 1 et 30) : \n");
    scanf("%d", &nombre);
  }
  int count;
  strcpy(data, "couleurs: ");
  char temp_string[10];
  sprintf(temp_string, "%d,", nombre);
  if (cc->size < 30) {
    sprintf(temp_string, "%d,", cc->size);
  }
  strcat(data, temp_string);
  
  //choisir 30 couleurs
  for (count = 1; count < nombre+1 && cc->size - count >0; count++) {
    if(cc->compte_bit ==  BITS32) {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc24[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    if(cc->compte_bit ==  BITS24) {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc32[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    strcat(data, temp_string);
  }

  //enlever le dernier virgule
  data[strlen(data)-1] = '\0';
}

int envoie_couleurs(int socketfd, char *pathname) {
  char data[1024];
  memset(data, 0, sizeof(data));
  analyse(pathname, data);
  
  //printf("%s", data);
  strcpy(data,StringToJSON(data));

  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  return 0;
}

char *JsonToString(char *data){
  int sizeOfData = strlen(data);
  int WriteEverything = 0;
  int FirstColor = 0;
  int TypeOfTransmission;
  char *RetString = malloc(sizeof(char)*1024);
  char Mot[100] = {};
  int indexBuff = 0;
  for(int i = 0; i<sizeOfData; i++){
    if (data[i] == '\"'){
      if (indexBuff == 0){
	      indexBuff=i;
      }
      else{
        for(int j = 0; j<i-indexBuff-1; j++){
          Mot[j] = data[j + indexBuff + 1];
        }
        indexBuff = 0;
	//printf("%s\n",Mot);
	if (strcmp(Mot,"message") == 0){
		strcpy(RetString, Mot);
		strcat(RetString, ": ");
		TypeOfTransmission = 1;
	}
	else if(strcmp(Mot,"calcule") == 0){
		strcpy(RetString, Mot);
		strcat(RetString, ": ");
		TypeOfTransmission = 2;
	}
	else if(strcmp(Mot,"couleurs") == 0){
		strcpy(RetString, Mot);
		strcat(RetString, ": ");
		TypeOfTransmission = 3;
	}
	else if(strcmp(Mot,"valeurs") == 0){
		WriteEverything = 1;
	}
	else if(WriteEverything == 1){
		//signe précédent
		if (TypeOfTransmission == 3){
			if (FirstColor == 0){
				FirstColor = 1;
			}
			else{
				strcat(RetString,",#");
			}
		}	
		strcat(RetString,Mot);
		//séparateur
		if (TypeOfTransmission == 2){
		strcat(RetString," ");
		}
	}
	memset(Mot, 0, sizeof(Mot));
      }
    }
  }
  //printf("%s\n",RetString);
  return RetString;
}

char *StringToJSON(char *data){
	int sizeOfData = strlen(data);
	char *RetString = malloc(sizeof(char)*1024);
	int TypeOfTransmission;
	int WriteEverything = 0;
	char Mot[1024] = {};
	int indexBuff = 0;
	int firstColor = 0;
	strcat(RetString, "{\"code\" : \"");
	for(int i = 0; i<sizeOfData; i++){
    		if (data[i] == ':'){
        		for(int j = 0; j<i; j++){
         			Mot[j] = data[j];
			}
			//printf("%s\n",Mot);
			strcat(RetString,Mot);
			strcat(RetString, "\",\"valeurs\" : [\"");
			if (strcmp(Mot,"message") == 0){
				TypeOfTransmission = 1;
			}
			else if(strcmp(Mot,"calcule") == 0){
				TypeOfTransmission = 2;
			}
			else if(strcmp(Mot,"couleurs") == 0){
				TypeOfTransmission = 3;
			}
			memset(Mot, 0, sizeof(Mot));
		}
		switch(TypeOfTransmission){
			case 1:
				if (WriteEverything == 1){
					char cToStr[2];
					cToStr[1] = '\0';
					cToStr[0] = data[i];
					strcat(RetString, cToStr);
				}
				if ((data[i] ==  ' ') && (data[i-1] == ':')){
					WriteEverything = 1;
				}
				break;
			case 2:
				if (data[i] == ' ' || i == sizeOfData-1){
					if (i == sizeOfData-1){
						i++;
					}
					if (indexBuff == 0 || indexBuff == 7){
						indexBuff = i+1;
					}
					else{
						for(int j = 0; j<i-indexBuff; j++){
			 				Mot[j] = data[indexBuff+j];
						}
						strcat(RetString,Mot);
						if (i != sizeOfData){
							strcat(RetString,"\",\"");
						}
						indexBuff = i+1;
						memset(Mot, 0, sizeof(Mot));
					}
				}
				
			break;
			case 3:
				if (data[i] == ' '){
					indexBuff = i+1;
				}
				else if (data[i] == ',' && indexBuff !=0){
					for(int j = 0; j<i-indexBuff; j++){
			 			Mot[j] = data[indexBuff+j];
					}
					strcat(RetString,Mot);
					strcat(RetString,"\",\"");
					memset(Mot, 0, sizeof(Mot));
				}
				else if (data[i] == '#'){
					indexBuff = i+1;
					firstColor = 1;
				}
				else if ((data[i] == ',' || i == sizeOfData-1) && firstColor == 1){
					if (i == sizeOfData-1){
						i++;
					}
					for(int j = 0; j<i-indexBuff; j++){
			 				Mot[j] = data[indexBuff+j];
						}
						strcat(RetString,Mot);
						if (i != sizeOfData){
							strcat(RetString,"\",\"");
						}
						indexBuff = i+1;
						memset(Mot, 0, sizeof(Mot));
				}
		}
		
	}
	strcat(RetString, "\"]}");
	//printf("%s\n",RetString);
	return RetString;	
}

int main(int argc, char **argv) {
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

  int valid = 0;
  while (valid == 0) {
    printf("Choisissez une fonction : message, calcule ou couleurs\n");
    char input[16];
    fgets(input, 15, stdin);
    if (strcmp(input, "message") == 10){
      envoie_recois_message(socketfd);
      valid = 1;
    }
    else if (strcmp(input, "calcule") == 10){
      envoie_operateur_numeros(socketfd);
      valid = 1;
    }
    else if (strcmp(input, "couleurs") == 10){
      printf("Le chemin doit être renseigné lors du lancement du programme (ex : \"./client ./images/800px-2006-10-18Dahlia03m.bmp\"\n");
      envoie_couleurs(socketfd, argv[1]);
      valid = 1;
    }
  }

  close(socketfd);
}
