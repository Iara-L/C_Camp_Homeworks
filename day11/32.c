#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_d(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void print_arr(double* arr, int size){
    for (int i = 0; i < size; i++) {
        printf("%lf ", arr[i]);
    }
}

int main(){
    srand(time(NULL));

    double* arr;
    int n, m, p;

    scanf("%d", &n);

    arr = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand_d(0.0, 1.0);
    }
    print_arr(arr, n);
 
    scanf("%d", &m);
    arr = realloc(arr, sizeof(double) * (n + m));
    
    for (int i = 0; i < n + m; i++) {
        arr[i] = rand_d(1.0, 2.0);
    }
    print_arr(arr, n + m);

    scanf("%d", &p);
    arr = realloc(arr, sizeof(double) * (n + m + p));

    for (int i = 0; i < n + m + p; i++) {
        arr[i] = rand_d(2.0, 3.0);
    }
    print_arr(arr, n + m + p);

    free(arr);

    return 0;
}
