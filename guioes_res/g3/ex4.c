#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int mysystem(char*c){

char*arr[20];
    int count=0;
    char *token;
    for(token=strtok(c,"  \n");token!=NULL;token=strtok(NULL,"  \n"))
    {
        arr[count]=strdup(token);
        count++;
    }
    arr[count]=NULL;
    
    if (fork()==0) {
        execvp(arr[0],arr);
    }
}


int main(int argc,char* argv[])
{
char str[] ="./e1.exe";

mysystem(str);

}