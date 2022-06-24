#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>


int main(){
    int novo[2];
  

    if(pipe(novo)!=0){
        perror("pipe");
        return -1;
    }

    pid_t pid = fork();
    if(!pid){
        dup2(novo[1],STDOUT_FILENO);
        close(novo[0]);
        close(novo[1]);
        execlp("ls", "ls", "/etc", NULL);
    }
    else{
        dup2(novo[0],STDIN_FILENO);
        close(novo[1]);
        close(novo[0]);
        execlp("wc", "wc", "-l", NULL);
    }
    return 0;

}