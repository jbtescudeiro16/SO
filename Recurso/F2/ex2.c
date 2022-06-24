#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>



int main(int argc,char*argv[])
{


    pid_t proc = fork();
    if(proc < 0) _exit(1);

    if(proc == 0)
    {
        pid_t childPID = getpid();
        pid_t childPPID = getppid();
        printf("id criança = %d\nid pai = %d\n", childPID, childPPID);
    }
    else 
    {
        pid_t parentPID = getpid();
        pid_t parentPPID = getppid();
        pid_t parentChildPID = proc;
        printf("id do pai = %d\nid do avo = %d\nid da criança = %d\n\n", parentPID, parentPPID, parentChildPID);
        wait(NULL);
    }
}