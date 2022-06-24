#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(int argc,char* argv[]){

int res=0;
int commandindex=1;
char command[1024];
int ifd,ofd;
bzero(command,1024);


if (strcmp(argv[commandindex],"-i")==0){
    ifd=open(argv[commandindex+1],O_RDONLY);
    res=dup2(ifd,0);
    close(ifd);
    commandindex+=2;
}
if(strcmp(argv[commandindex],"-o")==0){
    ofd=open(argv[commandindex+1],O_CREAT|O_TRUNC|O_WRONLY,0666);
    res=dup2(ofd,1);
    close(ofd);
    commandindex+=2;
}
while(commandindex<argc){
    strcat(command,argv[commandindex]);
    strcat(command," ");
    commandindex++;
}
system(command);
return 0 ;
}
