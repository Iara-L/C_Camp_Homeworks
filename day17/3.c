#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    fflush(stdout);
    pid_t pid = fork();

    if(pid == -1){
        perror("fork");
        return EXIT_FAILURE;
    }

    if(pid == 0){
        //child
        execlp("ls", "ls", NULL);
    } else{
        //parent
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)){
            int statuscode = WEXITSTATUS(wstatus);
            if(statuscode == 0){
                wait(NULL);
                execlp("cal", "cal", NULL);
                exit(0);
            }
        }
    }
    return EXIT_SUCCESS;
}