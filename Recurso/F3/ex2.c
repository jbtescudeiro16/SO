#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main (int argc,char*argv[]){

    if (fork()==0){
    execlp("ls","ls","-l",NULL);
    }
    wait(NULL);
   printf("executou");
}