#include <stdio.h>
#include <string.h>

unsigned int my_strlen(char* str);
unsigned int my_strnlen(char* str, int maxlen);
char* my_strcpy(char* from, char* to);
char* my_strncpy(char* from, char* to, int maxlen);
char* my_strcat(char* from, char* to);
char* my_strncat(char* from, char* to, int maxlen);
int my_strcmp(char* first, char* second);
unsigned int my_strncmp(char* first, char* second, int len);
char* my_strstr(char* haystack, char* needle);


int main(){
    char mystr[10];
    char from[10] = "Hello!";
    char to[500] = "My name is Alex.";
    char str3[10] = "123";

    char* res = my_strstr("Haystack", "cka");

    //printf("%d\n", my_strlen("Hello"));
    //printf("%d\n", my_strnlen("He", 3));
    //printf("%s\n", my_strcpy(from, to));
    //printf("%s\n", my_strncpy(str3, to, 3));
    //printf("%s\n", my_strncat(from, to, 1));
    //printf("%d\n", my_strncmp("Ya", "Yara", 5));
    if(res == NULL){
        printf("NULL\n");
    }else{
        printf("%s\n", res);
    }

    return 0;
}

unsigned int my_strlen(char* str){
    int len = 0;

    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

unsigned int my_strnlen(char* str, int maxlen){
int len = 0;

    while (*str != '\0' && len < maxlen) {
        len++;
        str++;
    }
    return len;
}

char* my_strcpy(char* from, char* to){
    for(int i = 0; from[i] != '\0'; i++){
        to[i] = from[i];
    }
    return to;
}

char* my_strncpy(char* from, char* to, int maxlen){
    for(int i = 0; from[i] != '\0' && i < maxlen; i++){
        to[i] = from[i];
    }
    to[maxlen] = '\0';
    return to;
}

char* my_strcat(char* from, char* to){
    int to_len = strlen(to);
    for(int i = 0; i < strlen(from) + 1; i++){
        to[to_len + i] = from[i];
    }
    return to;
}

char* my_strncat(char* from, char* to, int maxlen){
    int to_len = strlen(to);
    int i;
    for(i = 0; i < strlen(from) + 1 && i < maxlen; i++){
        to[to_len + i] = from[i];
    }
    to[to_len + i] = '\0';

    return to;
}

int my_strcmp(char* first, char* second){
    for(int i = 0; first[i] != '\0' || second[i] != '\0'; i++){
        if(first[i] > second[i]){
            return 1;
        }else if(first[i] < second[i]){
            return -1;
        }
    }
    return 0;
}

unsigned int my_strncmp(char* first, char* second, int len){
    for(int i = 0; (first[i] != '\0' || second[i] != '\0') && i < len; i++){
        if(first[i] > second[i]){
            return 1;
        }else if(first[i] < second[i]){
            return -1;
        }
    }
    return 0;
}

char* my_strstr(char* haystack, char* needle){
    for(int i = 0; i < strlen(haystack); i++){
        int b = 1;
        for (int j = 0; j < strlen(needle); j++){
            if((i + j) > strlen(haystack)){
                b = 0;
                break;
            }
            if(haystack[i + j] != needle[j]){
                b = 0;
                break;
            }
        }
        if(b == 1 ){
            return haystack + i;
        }
    }
    return NULL;
}