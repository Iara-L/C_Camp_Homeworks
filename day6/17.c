#include <stdio.h>
#define PI 3.141592
#define PRECISION 8

double my_pow(double base, int exp){
    double result = base;

    if(exp < 0) {
        if(base == 0)
            return -0;
        return 1 / (base * my_pow(base, (-exp) - 1));
    }
    if(exp == 0){
        return 1;
    }
    if(exp == 1){
        return base;
    }
    return base * my_pow(base, exp - 1);
}

int fact(int n) {
    if(n <= 0){
        return 1;
    }
    return n * fact(n - 1);
}

double sine(int deg) {
    deg %= 360; 
    double rad = deg * PI / 180;
    double sin = 0;

    int i;
    for(i = 0; i < PRECISION; i++) {
        sin += my_pow(-1, i) * my_pow(rad, 2 * i + 1) / fact(2 * i + 1);
    }
    return sin;
}

int main(){

    printf("%lf\n", sine(59));

    return 0;
}