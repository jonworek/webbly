/* 
   File: main.c

   Description: Main program file for webbly 

   Author: Jonathan Worek
*/

#include <stdio.h>

#include "server.h"

int main(int argc, char* argv[]) {
  printf("Starting Webbly web server...\n");

  start_server();

  printf("Exiting Webbly web server...\n");

  return 0;
}
