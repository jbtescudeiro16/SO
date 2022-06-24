#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>




int main(int argc,char*argv[]){

    int res=0;
    int p[2];
    char buffer[MAX_LINE_SIZE];
    int pid;
    int status;


    if(pipe(p)!=0){
        perror("pipe");
        return -1;
    }

    switch((pid=fork())){
        case 0:
        //filho
        close(p[1]);
        dup2(p[0],0);
        res=execlp("wc","/bin/wc",NULL);
        _exit(0);
   
        default:
        printf("pai pid: %d  , filho tem pid %d\n",getpid(),pid);
        close(p[0]);
        while((res=readln(0,buffer,MAX_LINE_SIZE)>0){
            write(p[1],buffer,res);
        }
    close(p[1]);
    wait(&status);
    if(WIFEXISTSTATUS(status)){
    printf("filho terminado com %d\n",WEXITSTATUS(status));
    }

   
    }

}