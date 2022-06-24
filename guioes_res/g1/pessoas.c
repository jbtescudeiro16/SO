#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef struct pessoa {
    int idade;
    char *nome;
}PESSOA;


int main(int argc , char const *argv[]){
    if (argc!=4) {
        puts ("Invalid input \n" );
        exit(1);
    }

    int f =0;
    if (strcmp(argv[1],"-i") ==0 ){
        f= open("./pessoas.txt",O_WRONLY,O_CREAT,0664);
        if (f<0) {
            perror("cant open file");
            exit(1);
        }

    struct pessoa person ;
    person.idade = atoi(argv[3]);
    strcpy(person.nome,argv[2]);
    int pos = lseek(f,0,SEEK_END);
    if (write(f,&person,sizeof(person))<=0) {
        perror ("cant write");
        exit(1);
    }
    char line [100];
    int n = snprintf(line,sizeof(line),"registo %d\n",pos);
    write(1,line,n);
    close (f);
    }
    

    else if (strcmp(argv[1],"-u")==0){
        f=open ("./pessoas.txt",O_RDWR);
        if (f<0){
            perror("pessoas.txt");
            exit(1);
        }
        int n=0;
        struct pessoa person;
        while ((n=read(f,&person,sizeof(person)))>0){
            if (strcmp(person.nome,argv[2])==0){
                person.idade = atoi(argv[3]);
                lseek(f,-sizeof(person),SEEK_CUR);
                if(write(f,&person,sizeof(person))<=0){
                    perror ("cant write");
                    exit(1);
                }
            }
        }
        close(f);
    }
     else if (strcmp(argv[1],"-o")==0){
         f=open("./pessoas.txt",O_RDWR);
         int n=0;
         struct pessoa person;
         lseek(f,atoi(argv[2]),SEEK_SET);
         if (read(f,&person,sizeof(person))<=0){
             perror("error reading");
             exit(1);
         }
         person.idade=atoi(argv[3]);
         lseek(f,-sizeof(person),SEEK_CUR);
         if (write(f,&person,sizeof(person))<=0){
             perror("Error writing");
             exit(1);
         }
         close(f);
}
}