#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t id = fork();
    int n;
    if (id ==0){
        n = 1;
    }else{
        //the parent process
        waitpid(id, NULL, 0);
        n = 6;
    }

    int i;
    for (i=n;i<n+5;i++){
        printf("%d ", i);
        fflush(stdout);//print everytime we have something
    }
    //printf("\n");
    return 0;
}