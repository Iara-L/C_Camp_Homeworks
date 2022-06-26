#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COUNT 5

typedef struct Book{
    char title[151];
    char author[101];
    unsigned int pages;
    double price;
} Book;

int int_rand(int min, int max);
double double_rand(double min, double max);
char* rand_title(char* titles);

int main(int argc, char** argv){
    srand(time(NULL));

    Book books[COUNT];

    FILE *fr = fopen(argv[1], "rb");
    if(fr == NULL){
        fprintf(stderr, "Reading problem.\n");
        return EXIT_FAILURE;
    }

    int arr[COUNT];

    for(int i = 0; i < COUNT; i++){
        scanf("%d", arr[i]);
    }

    for(int i = 0; i < COUNT; i++){
        //fread(&books[i], sizeof(Book), 1, fr);
        rand_title(books[i].title);
        rand_title(books[i].author);
        books[i].pages = int_rand(5, 2000);
        books[i].price = double_rand(1.00, 1000.00);
    }
    fclose(fr);

    for(int i = 0; i < COUNT; i++){
        printf("%s\t", books[i].title);
        printf("%s\t", books[i].author);
        printf("%d\t", books[i].pages);
        printf("%lf\n", books[i].price);
    }

    FILE *fw = fopen(argv[1], "wb");
    if(fw == NULL){
        fprintf(stderr, "Writing problem.\n");
        return EXIT_FAILURE;
    }
    
    for(int i = 0; i < COUNT; i++){
        fwrite(&books[i], sizeof(Book), 1, fw);
    }

    fclose(fw);

    return 0;
}

int int_rand(int min, int max){
    return (rand() % (max - min)) + min;
}

double double_rand(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* rand_title(char* titles){
    int index = 0;
    titles[index++] = int_rand('A', 'Z');
    
    for(index = 1; index < int_rand(4, 9); index++){
        titles[index] = int_rand('a', 'z');
    }
    titles[index++] = ' ';

    titles[index++] = int_rand('A', 'Z');
    for(int i = 0; i < int_rand(4, 9); i++){
        titles[index++] = int_rand('a', 'z');
    }
    titles[index++] = '\0';

    return titles;
}