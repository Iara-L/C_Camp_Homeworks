#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n){
    unsigned int sum = 0;
    
    for(int i = 0; i < n; i++){
        int value = arr[i];
        while(value > 0){
            int lastDigit = value - (value / 10) * 10;
            value /= 10;
            sum += lastDigit;
        }
    }
    return sum;
}

int main(){
    int arr[] = { 12, 34, 5, 70 };

    printf("%d\n", sumArrayDigits(arr, 4));

    return 0;
}