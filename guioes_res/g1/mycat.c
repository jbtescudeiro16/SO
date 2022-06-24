#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX_BUFFER 1024*1024

int main(int argc ,char *argv[])
{
    char *buffer = malloc(MAX_BUFFER);
    int bytes_read;
    int fd_origem;

    while((bytes_read=read(0,buffer,MAX_BUFFER))>0)
    {
        write(1,buffer,bytes_read);

    }
    return 0;
}