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

#define SERVER_LISTEN_PORT 3000

char read_buff[1024];

int start_server();
char* create_response();

int start_server() {
  int listenfd = 0, connfd = 0;
  int bytes_read = 0, bytes_written = 0;
  struct sockaddr_in serv_addr;
  char* response;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(send_buff, '0', sizeof(send_buff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(SERVER_LISTEN_PORT);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  printf("Webbly web server is now running and waiting for connections.\n");

  while(1) {
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

    bytes_read = read(connfd, read_buff, 1024);
    puts(read_buff);

    response = create_response();
    write(connfd, response, strlen(response));

    close(connfd);
    sleep(1);
  }
}

char* create_response() {
  return 
    "HTTP/1.1 200 OK\n"
    "Connection: close\n"
    "\r\n\r\n"
    "<html><body><h1>Hello Webbly!!</h1></body></html>";
}
