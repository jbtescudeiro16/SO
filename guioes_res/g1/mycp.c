#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>




#define MAX_BUF 1024*2014


//Descritores de ficheiros 

//0- standard input
//1- standard output
//2- strandard error 

//ver o tempo (time ./porgram a b)




int main(int argc, char *argv[]) 
{
/*
printf ("argv[0] =  %s \n",argv[0]);
printf ("argv[1] =  %s \n",argv[1]);
printf ("argv[2] =  %s \n",argv[2]);
*/

char* buffer=malloc(MAX_BUF);

int fd_origem,fd_destino;


    if ((fd_origem = open(argv[1],O_RDONLY))==-1)
    {
        printf("MSG :%s,NR : %d \n",strerror(errno),errno);
        perror("erro no open origem\n");
    
    }

    if ((fd_destino=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC ,0640)==-1))
    {
    perror("erro no open destino\n");
    return -1;
    }
    
    int bytes_read;

    while((bytes_read=read(fd_origem,buffer,MAX_BUF))>0)
    {
        write(fd_destino,buffer,bytes_read);

    }

    free(buffer);
    close(fd_origem);
    close(fd_destino);
    return 0;

}