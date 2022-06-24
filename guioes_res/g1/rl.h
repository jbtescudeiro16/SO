#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER 4096

ssize_t readln(int fd, char *line, size_t size);
ssize_t readln2(int fd, char *line, size_t size) ;
int readc (int fd,char *c);