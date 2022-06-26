#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int int_rand(int min, int max);
char* rand_string(char* str);

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("Fork error\n");
            return EXIT_FAILURE;
        }
        if(pid == 0){
            srand(time(NULL) + i);
            //child
            char* str;
            printf("%s\n", rand_string(str));
            sleep(1);

            return EXIT_SUCCESS;
        }
    }
    for (int i = 0; i < N; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}

int int_rand(int min, int max){
    return (rand() % (max - min)) + min;
}

char* rand_string(char* str){
    int index = 0;
    
    for(index = 0; index < 10; index++){
        str[index] = int_rand('a', 'z');
    }

    return str;
}
