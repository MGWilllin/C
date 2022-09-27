#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/wait.h>
//redirection
#include <fcntl.h>

int main(int argc, char* argv[]){
    //lets do piping now
    //main process will create the pipe.
    //make some smart redirection with the pipe to make your piping work
    int fd[2];

    //just checking if our pipe is created or not
    if (pipe(fd) == -1){
        return 1;
    }
    
    int pid1 = fork();
    //check if forking failed
    if (pid1 <0){
        return 2;
    }


    if (pid1 ==0){
        //child process 1 (ping)
        //before execlp, we want to reroute for piping
        dup2(fd[1], STDOUT_FILENO); //now stdout == fd[1]
        //STDOUT_FILENO = 1
        close(fd[0]);
        close(fd[1]);
        execlp("ping","ping","-c", "5", "google.com", NULL);
    }

    int pid2 = fork();
    if (pid2 <0){
        return 3;
    }

    if (pid2 ==0){
        //child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        execlp("grep","grep","rtt", NULL);
    }

    //close the fds in the parent too!
    close(fd[0]);
    close(fd[1]);

    //executed by parent, no need to put into else
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);



    return 0;
   
}