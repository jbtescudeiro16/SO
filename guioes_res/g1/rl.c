#include "rl.h"

ssize_t readln2(int fd, char *line, size_t size) {
    int bytes = read(fd,line,size-1);
    if (bytes<=0) return bytes;
    line[size-1] = '\0';
    int kline = strcspn(line , "\n")+1;
    if (bytes <kline) kline = bytes;
    line [kline]='\0';
    lseek(fd,-(bytes-kline),SEEK_CUR);
    return kline;

}


//com o artur
/*
ssize_t readln(int fd, char *line, size_t size) 
{
  ssize_t  bytes = 0;

  int c =0 ;
  while (c < size-1) {
      //caractere a caractere 
    // se o read der erro retorna -1
      int bytes = read(fd,&line[c],1);
      if (bytes <=0 ) break;
      if (line[c] == '\n') {
          c++;
          break;
      }
  }
      line[c]='\0';
      return c;
}

*/

int readc (int fd,char *c){
    return read(fd,c,1);
}

//le m char com o read para o bufer->readc
//temos de verificar se é um \n ou se o tamanho do buf é excedido

ssize_t readln(int fd, char *line, size_t size) {
    int i =0;
    while(i<size && readc(fd,&line[i])>0){
        i++;
        if(((char*)  buf)[i-1]=="\n"){
            return i;
        }
    }
}