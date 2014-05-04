CC=gcc

webbly:
	cd src && \
  	$(CC) main.c server.c -o ../bin/webbly
