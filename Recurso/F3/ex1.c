#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main (int argc,char*argv[]){


    execlp("ls","ls","-l",NULL);

   printf("executou");
}