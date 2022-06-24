#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

 // se for 0 tamos no filho
int main(int argc,char*argv[]) {

int exitstatus;
    for(int i=0;i<10;i++){

        
        if (fork()==0) {
            printf(" criei filho\n");
            _exit(i);
        }
    }

    for(int i=0;i<10;i++){
        
        wait(&exitstatus);
        int k = WEXITSTATUS(exitstatus);
        printf("%d -EXITSATTUS\n",k);
    }
    printf("Acabou o pai\n");

}