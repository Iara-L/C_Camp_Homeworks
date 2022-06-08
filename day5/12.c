#include <stdio.h>

int triangle(double a, double b, double c, double*, double*);

int main(){
    double a, b, c, S = 0, P = 0;

    while(1){
    if(scanf("%lf %lf %lf", &a, &b, &c) == EOF)
        break;
    
        int res = triangle(a, b, c, &S, &P);

        if(res == 0){
            printf("S = %lf\nP = %lf", S, P);
        }else{
            fprintf(stderr, "\nInvalid triangle sides\n");
        }

    }

    return 0;
}

int triangle(double a, double b, double c, double* S, double* P){
    if(a > 0 && b > 0 && c > 0){
        *S = (a + b + c) / 2;
        *P = a + b + c;
        return 0;
    }
    return -1;
}