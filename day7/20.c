#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 0.00001

int compare(double a, double b){
    if(fabs(a - b) < epsilon){
        return 0;
    }else if(a > b){
        return -1;
    }
    return 1;
}

int secondMax(const double* arr, size_t n, double* sMax){
    double Max = arr[0];
    int maxElements = 0;

    if(n == 0){
        return -1;
    }
    if(n == 1){
        return -2;
    }

    for(int i = 0; i < n; i++){
        double value = arr[i];
        int compResult = compare(value, Max);

        if(compare(value, *sMax) == -1){
            *sMax = value;
        }
        if(compResult == -1){
            *sMax = Max;
            Max = value;
            maxElements = 0;
        }else if(compResult == 0){
            maxElements++;
        }
    }
    if(maxElements == n){
        return -3;
    }
}

int main(){
    double sm = 0;
    double arr[] = {  };

    int result = secondMax(arr, 0, &sm);

    if(result == -1){
        fprintf(stderr, "\nArray is empty.\n");
    }else if(result == -2){
        fprintf(stderr, "\nArray contains 1 element only.\n");
    }else if(result == -3){
        fprintf(stderr, "\nElemets in array are equal.\n");
    }else if(result == 0){
        printf("%lf\n", sm);
    }

    return 0;
}