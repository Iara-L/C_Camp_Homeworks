#include <stdio.h>
#include <math.h>

// build-in compare operator
int floatCompare1(float a, float b) {
    return a == b;
}

// fixed epsilon
int floatCompare2(float a, float b) {
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int floatCompare3(float a, float b) {
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}

// build-in compare operator
double doubleCompare1(double c, double d) {
    return c == d;
}

// fixed epsilon
double doubleCompare2(double c, double d) {
    return fabs(c - d) < 1.0e-5;
}

// adaptive epsilon
double doubleCompare3(double c, double d) {
    return fabs(c - d) < 1.0e-5 * fmax(fabs(c), fabs(d));
}

int main(void) {
    float a = 0.00001f;
    float b = 0.0001f;

    double c = 0.00002;
    double d = 0.0002;

    int succeed = 0;
    int failed = 0;

    //float compare
    for (int i = 0; i < 1000; i++, b += 0.1f, a += 0.1f) {
        if (floatCompare1(a, b)) {
            succeed++;
        }
        else {
            failed++;
            printf("%f %f \n", a, b);
        }
        if (floatCompare2(a, b)) {
            succeed++;
        }
        else {
            failed++;
        }
        if (floatCompare3(a, b)) {
            succeed++;
        }
        else {
            failed++;
        }
    }


    //double compare
    for (int i = 0; i < 1000; i++, d += 0.1, c += 0.1) {
        if (doubleCompare1(c, d)) {
            succeed++;
        }
        else {
            failed++;
        }
        if (doubleCompare2(c, d)) {
            succeed++;
        }
        else {
            failed++;
        }
        if (doubleCompare3(c, d)) {
            succeed++;
        }
        else {
            failed++;
        }
    }

    printf("Succeed: %d", succeed);
    printf("\nFailed: %d", failed);

    return 0;
}