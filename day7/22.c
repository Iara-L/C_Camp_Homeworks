#include <stdio.h>

int sum(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

void arryEvluate(int* arr, size_t n, int(*f)(int*, int)){
    int result = 0;
    for(int i = 0; i < n; i++){
        result = f(arr, n);
    }
    printf("Value: %d\n", result);
}

int main(){
    int arr[] = { 1, 2, 3 };

    arryEvluate(arr, 3, sum);

    return 0;
}