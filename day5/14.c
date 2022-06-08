#include <stdio.h>
#include <math.h>

int quadEq(double, double, double, double*, double*);

int main(){
double a, b, c, S = 0, P = 0;

    while(1){
        if(scanf("%lf %lf %lf", &a, &b, &c) == EOF)
            break;
    
        int res = quadEq(a, b, c, &S, &P);

        if(res == 0){
            printf("\nx1 = %lf\nx2 = %lf\n", P, S);
        }else{
            fprintf(stderr, "\nNo real roots\n");
        }

    }

    return 0;
}

int quadEq(double a, double b, double c, double* S, double* P){
    double D;
    D = (b * b) - 4 * a * c;

    if(D >= 0){
        *S = (-b + sqrt(D)) / (2 * a);
        *P = (-b - sqrt(D)) / (2 * a);
        return 0;
    }
    return -1;
}