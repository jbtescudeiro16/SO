#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main () {
    printf("pid : %d\n",getpid());
    printf("filho-pid pai :  %d \n",getppid());
return 0;
}
