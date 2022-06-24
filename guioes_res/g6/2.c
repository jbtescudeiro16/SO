#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stats.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>


void creates_fifo() {
    if (mkfifo("CLIENTE", 0666) ==-1) {
        perror("Não foi possível criar o fifo.\n");
        return;
    }
}


void read_fifo() {
    int fd = open("CLIENTE", O_RDWR);
    int nfd = open("log.txt", O_CREAT | O_RDWR, 0666);

    printf("Aberto\n");

    size_t rd;
    char buf[1024];

    while ((rd = read(fd, buf, 1024)) > 0) {
        write(nfd, buf, rd);
    }
    close(fd);
}