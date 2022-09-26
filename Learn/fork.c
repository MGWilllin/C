#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //linux library only


int main(int argc, char* argv[]){
    int id = fork();

    //lets use waitpid
    if (id == -1){
        printf("Error creating process");
        return 1;
    }

    if (id == 0){
        sleep(4);
        printf("finish execution (%d)\n", getpid());
        return 0;
    }

    int id2 = fork();
    if (id2 == -1){
        printf("error creating process");
        return 2;
    }
    if (id2 ==0){
        sleep(1);

        printf("finish execution (%d)\n", getpid());

        return 0;
    }

    int id1_res = waitpid(id, NULL, 0);
    printf("Waited for %d\n", id1_res);
    int id2_res = waitpid(id2, NULL, 0);
    printf("Waited for %d\n", id2_res);


   /* //wait for process to finish to continue next
    int status;
    if (id == 0) {
        status = 1;
    
    } else {
        status = 6;
    }
    if (id != 0) {
        wait();
    }

    int i;
    for (i = status; i < status+5; i++){
        printf("%d", i);
        fflush(stdout);
    }
    if (id != 0){
        printf("\n");

    }
*/
   // pid_t waitpid(id, *status);

   /* if (id == 0) {
        printf("hello from child process id: %d\n", id);
    } else {
        printf("Hello from Parent process id: %d\n", id);
    } */
    return 0;
}