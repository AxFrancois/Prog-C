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

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}
/*reçois les numéros et l'opérateur*/
int recois_numeros_calcule(char *data){

  char *op = malloc(sizeof(op));
  float num1 = 0;
  float num2 = 0;
  //on récupère les variables utiles qui se trouve dans data
  sscanf(data, "%*s %c %f %f", op, &num1, &num2);

  float resultat;

  switch((char)*op){
		case '*'  : resultat = num1 * num2  ;
			break;
		case '-' : resultat = num1-num2;
			break;
		case '+' : resultat = num1 + num2;
			break;
		case '/' : resultat = num1/num2;
			break;
		case '%' : resultat = (int)num1%(int)num2;
			break;
		case '&' : resultat = (int)num1&(int)num2;
			break;
		case '|' : resultat = (int)num1|(int)num2;
			break;
    case '~' : resultat = ~num1;
      break;
  }
return resultat;
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
  
  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);
  
  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) {
      char dataToCLient[1024];
      // la réinitialisation de l'ensemble des données
      memset(dataToCLient, 0, sizeof(dataToCLient));

      char messageToClient[100];
      printf("Votre message au client (max 1000 caracteres): ");
      fgets(messageToClient, 1024, stdin);
      strcpy(dataToCLient, "message: ");
      strcat(dataToCLient, messageToClient);

      renvoie_message(client_socket_fd, dataToCLient);
  }
  //Si le message commence par le mot: 'calcule:'
  if (strcmp(code, "calcule:") == 0) {

      //on appel la fonction qui va faire le calcul
      float calcul = recois_numeros_calcule(data);
      sprintf(data,"calcule: %f", calcul);
      printf("%s \n",data);
      renvoie_message(client_socket_fd, data);
  }

  //fermer le socket 
  close(socketfd);
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
