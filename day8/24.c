#include <stdio.h>

int f(int array){
    int res = array == 0 ? 0 : 1;
    return res;
}

void map(int* array, size_t n, int(*func)(int)){
    int res = 0;
    for(int i = 0; i < n; i++){
        res = func(array[i]);
        printf("%d\n", res);
    }
}

int main(){

    int arr[4] = { 1, 2, 0, 4};

    map(arr, 4, f);

    return 0;
}