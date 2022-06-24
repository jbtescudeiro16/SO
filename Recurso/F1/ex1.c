#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc,char*argv[]) {


char *buf[1000];

if (argc==0|| argc<3) {
     perror("Erro no número de inputs");
    return -1;
}

int k=open(argv[1],O_RDONLY,0660);

if (k<0){
    perror("Erro a abrir o ficheiro de entrada");
    return -1;
}
int i =0;
int obj=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0660);

if (obj<0){
    perror("Erro a abrir o ficheiro de saida");
    return -1;
}

while((i=read(k,buf,1000))>0){
    write(obj,buf,i);
}
return 0;

}