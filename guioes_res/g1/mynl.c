#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "rl.h"

int main ( int argc , char *argv[]) {
    int c =0;
    if (argc >1) c = open (argv[1],O_RDONLY);


    int i=0,k=0;
    char buf[4096];
    char line[100];
    

    while ((k=readln2(c,buf,sizeof(buf)))>0) {
        if (buf[k-1] == '\n') i++;
        size_t bytes =snprintf(line,sizeof(line), " %d ", i);
        write(1,line,bytes);
        write(1,buf,k);
    }
}

int main (int agrc,char*argv[]){
    int lincounter=0;
    char buffer[MAX_BUFFER];
    int bytes_read=0;

    int newline=1;
    while((bytes_read=readln(0,buffeR,MAX_BUFFER)>0)){
        char linenumber[10]="";
        if(newline&&buffer[0]=="\n"){
            snprintf(line_number,10,"%d",linecounter);
            write(1,line_number,sizeof(line_number));
            line_counter++;
        }
        write
        
    }
}