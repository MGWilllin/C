#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/wait.h>
//redirection
#include <fcntl.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        //child process
        //new file in file descriptor
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777); //BITWISE OR BETWEEN O_aaa
        //now file is in the nearest free space in file descriptor in kernel
        if(file == -1){
            return 2;
        }

        printf("The fd to pingResults: %d \n", file);

        //create a new file2 that will cope file and put it in STDOUT
        //replace file into 1 which is STDOUT! and STDIN is 0
        int file2 = dup2(file, 1);
        printf("The duplicated fd: %d \n", file2);
        close(file);
        close(file2); //now STDOUT should have the standard output

        int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
        if (err == -1){
            printf("Could not find program to execute! \n");
            return 2;
        }
    }
}