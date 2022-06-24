#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc,char* argv[]){

for(int i=1;i<argc;i++)
 {
    if (fork()==0){
        execlp(argv[i],argv[i],NULL);
        exit(-1);
    }
 }
 
 int exitstatus;
for(int i=1;i<argc;i++){
    wait(&exitstatus);
   if ( WIFEXITED(exitstatus)==1){
       if (WEXITSTATUS(exitstatus)!=-1)
       {
           printf("CORREU BEM\n");
       }
   }
}

}