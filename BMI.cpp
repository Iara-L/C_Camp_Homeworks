// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

float BMI(float weight, float height);
float BMI_new(float weight, float height);

int main() {
    float height, weight;

    printf("Enter your height: ");
    scanf_s("%f", &height);
    printf("\nEnter your weight: ");
    scanf_s("%f", &weight);

    printf("\nYOUR BMI IS: %f", BMI(weight, height));
    printf("\nYOUR BMI_new IS: %f \n", BMI_new(weight, height));

    return 0;
}

float BMI(float weight, float height) {
    return weight / pow(height, 2);
}

float BMI_new(float weight, float height) {
    return 1.3 * (weight / pow(height, 2.5));
}