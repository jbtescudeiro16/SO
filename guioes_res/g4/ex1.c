#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main () {

//para guardar o apotandor para o terminal
int copy0= dup(0);
int copy1= dup(1);
int copy2 = dup(2);

    int a = open("/etc/passwd.txt", O_RDONLY);
    int b = open("stdout.txt", O_WRONLY|O_CREAT|O_TRUNC,0666);
    int c = open("stderr.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);


    dup2(a,0);
    dup2(b,1);
    dup2(c,2);


    close(a);
    close(b);
    close(c);

    write(copy0,"Terminei\n",9);


return 0;    

}