#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int nproc=10;
    int status;
    for(int i=1;i<=nproc;i++){
        if((pid=fork())==0){
            printf("proc :%d  ; pid : %d \n",i,getpid());
            _exit(i);
        }
        else 
        {
            pid_t terminated=wait(&status);
            printf("(pai) process : %d exited , ecit code : %d \n",terminated,WEXITSTATUS(status));
        }
    }
            printf("o pai é %d",getpid());
}

