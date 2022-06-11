#include <stdio.h>
#define eps 0.000001

double my_sqrt(double n){
    for(double i = 0; i < 10; i += eps){
        if(n - i * i < eps){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("%.3lf\n", my_sqrt(4));
    printf("%.3lf\n", my_sqrt(100));
    printf("%.3lf\n", my_sqrt(49));
    printf("%.3lf\n", my_sqrt(15));

    return 0;
}