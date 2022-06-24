#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main ( int argc ,char *argv[]) {

    if(argc<2){
        printf("Usage programm neeedle \n");
        exit(-1);
    }
    pid_t pid ;
    int needle = atoi(argv[1]);
    int rows =10;
    int cols = 10000;
    int rand_max=10000;
    int status ;
    int **matrix;

    pid_t *arr;
    arr=(pid_t *)malloc(sizeof(pid_t)*rows);

    printf ("Generating numbers from 0 to %d \n ",rand_max );
    matrix=(int **)malloc(sizeof(int*)*rows);
    for (int i=0;i<rows ;i++)
    {
        matrix[i]=(int*) malloc(sizeof(int)*cols) ;
        
        for (int j =0;j<cols;j++)
        {
            matrix[i][j]=rand()%rand_max;
        }
    }
    printf("Done\n");


     for(int i = 0; i < rows; i++)
     {

        pid_t pid_child = fork();
        arr[i]=pid_child;

        if(pid_child == 0)
        {

            for(int j = 0; j < cols; j++){
                if(m[i][j] == x)
                    exit(1);
            }
            exit(0);
        }
    }
    for(int i=0;i<rows;i++){
        int exitstatus;

        waitpid(arr[i],&exitstatus,0);
        if (WEXITSTATUS(exitstatus)==1){
            printf("%d\n",i);
        }

    }
}






}