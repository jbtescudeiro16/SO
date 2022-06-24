#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stats.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>


int main(int agrc,char*argv[]){
    if (mkfifo("fifo",0666)==-1) {
perror("mkfifo");
    }
    return 0;
}