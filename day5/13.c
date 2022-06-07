#include <stdio.h>

int rectangle(double, double, double*, double*);

int main(){
    double w, h, S = 0, P = 0;

    while(1){
    if(scanf("%lf %lf", &w, &h) == EOF)
        break;
    
        int res = rectangle(w, h, &S, &P);

        if(res == 0){
            printf("S = %lf\nP = %lf", S, P);
        }else{
            fprintf(stderr, "\nInvalid rectangle size\n");
        }

    }

    return 0;
}

int rectangle(double w, double h, double* S, double* P){
    if(w > 0 && h > 0){
        *S = w * h;
        *P = (w + h) * 2;
        return 0;
    }
    return -1;
}