#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


int mensagens (char*palavra, char*ficheiro){

    int p1[2];
    int p2[2];
    char buffer[1024];

    if (pipes(p1)==-1){
        perror("Erro a criar o primeiro pipe");
        return -1;
    }

    if (fork()==0)
    {
        close(p1[0]);
        dup2(p1[1],1);
        close(p1[1]);
        execlp("grep","grep",palavra,ficheiro,NULL);
    }
    
    if (pipes(p2)==-1){
        perror("Erro a criar o segundo pipe");
        return -1;
    }
    if (fork()==0){

        close(p2[0]);
        dup2(p1[0],0);
        close(p1[0]);
        dup2(p2[1],1);
        close(p2[1]);
        execlp("wc","wc","-l",NULL);
    }
    close (p2[1]);
    close(p1[0]);
    int bytes = read(p2[0],buffer,1024);
    buffer[bytes]='\0';
    return atoi(buffer);

}