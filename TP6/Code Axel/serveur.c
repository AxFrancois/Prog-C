/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

void plot(char *data) {
  char NbCouleurs[8];
  for(int i = 10; data[i] != ','; i++){
    NbCouleurs[i-10] = data[i];
  }
  int nbCouleur = atoi(NbCouleurs);
  float numeroCercle = 360/nbCouleur;
  //Extraire le compteur et les couleurs RGB 
  FILE *p = popen("gnuplot -persist", "w");
  printf("Plot");
  int count = 1;
  int n;
  char *saveptr = NULL;
  char *str = data;
  fprintf(p, "set xrange [-30:30]\n");
  fprintf(p, "set yrange [-30:30]\n");
  fprintf(p, "set style fill transparent solid 0.9 noborder\n");
  fprintf(p, "set title 'Top %d colors'\n", nbCouleur);
  fprintf(p, "plot '-' with circles lc rgbcolor variable\n");
  while(1) {
    char *token = strtok_r(str, ",", &saveptr);
    if (token == NULL) {
      break;
    }
    str=NULL;
    if (count == 0) {
      n = atoi(token);
    }
    else {
      // Le numéro 36, parceque 360° (cercle) / 10 couleurs = 36 -> numeroCercle car on est plus à 10 couleurs
      fprintf(p, "0 0 10 %f %f 0x%s\n", (count-1)*numeroCercle, count*numeroCercle, token+1);
    }
    count++;
  }
  fprintf(p, "e\n");
  printf("Plot: FIN\n");
  pclose(p);
}

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {

  strcpy(data, StringToJSON(data));

  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
  
  //Verification : est-ce un json ?
  if (strchr(data, '{') != NULL & strchr(data, '}') != NULL){
    strcpy(data, JsonToString(data));
  }

  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s", code);

  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) {
    //AJOUT 1
    memset(data, 0, sizeof(data));
    char message[1000];
    printf("Votre message (max 1000 caracteres): ");
    fgets(message, 1024, stdin);
    strcpy(data, "message: ");
    strcat(data, message);
	  //
    renvoie_message(client_socket_fd, data);
  }
  else if (strcmp(code, "calcule:") == 0) {
    char op = ' ';
    int num1, num2, result;
    sscanf(data,"%*s %c %d %d",&op, &num1, &num2);
    switch(op){
		// +
		case '+' : result = num1 + num2;
		break;
		// -
		case '-' : result = num1 - num2;
		break;
		// *
		case '*' : result = num1 * num2;
		break;
		// /
		case '/' : result = num1 / num2;
		break;
		// %
		case '%' : result = num1 % num2;
		break;
		// &
		case '&' : result = num1 & num2;
		break;
		// |
		case '|' : result = num1 | num2;
		break;
		default: result = -1;
    }
    // ICI CONVERTIR RESULT DE INT EN CHAR ET AJOUTER CALCULE DEVANT 
    memset(data, 0, sizeof(data));
    strcpy(data, "calcule: ");
    char strResult[100];
    sprintf(strResult, "%d", result);
    strcat(data, strResult);
    

    renvoie_message(client_socket_fd, data);
  }
  else if (strcmp(code, "couleurs:") == 0){
    plot(data);
  }

  //fermer le socket 
  close(socketfd);
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

int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client
  recois_envoie_message(socketfd);

  return 0;
}
