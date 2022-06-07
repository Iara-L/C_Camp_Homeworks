#include <stdio.h>

int main(){
    double a, b;
    char operation;

    while (1) {
        int result = scanf("%lf %c %lf", &a, &operation, &b);

        if(result == EOF)
            break;

        if(operation == '+'){
            printf("%.2lf\n", a + b);
        }else if(operation == '-'){
            printf("%.2lf\n", a - b);
        }else if(operation == 'x'){
            printf("%.2lf\n", a * b);
        }else if(operation == '/'){
            printf("%.2lf\n", a / b);
        }else{
            fprintf(stderr, "\nInvalid data\n");
        }
    }

    return 0;
}