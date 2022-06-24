#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc,char*argv[]){
    char*buff[1000];

    while ((read(1,buff,1000))>0){
        write(0,buff,1000);
    }
    return 0;
}