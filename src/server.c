/* 
   File: server.c

   Description: The main server loop for the web server.
    Accepts connections, reads from socket and delegates the
    request to other functions.

   Author: Jonathan Worek
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int start_server() {
  int listenfd = 0, connfd = 0;
  struct sockaddr_in serv_addr;
  char send_buff[1024];

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(send_buff, '0', sizeof(send_buff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(3000);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  printf("Webbly web server is now running and waiting for connections.\n");

  while(1) {
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

    sprintf(send_buff, 
      "HTTP/1.1 500 Internal Server Error\n"
      "Connection: close\n"
      "\r\n\r\n");

    write(connfd, send_buff, strlen(send_buff));

    close(connfd);
    sleep(1);
  }
}
