#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


//esta bem 
int main( int argc,char*argv[]){


    printf("filho -> %d",getpid());
    printf ("pai -> %d",getppid());


}

