#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void* valuePtr, uint8_t flag){
    switch(flag){
        case TINT:
            printf("%d\n", *((int*)valuePtr));
            break;
        case TCHAR:
            printf("%c\n", *((char*)valuePtr));
            break;
        case TDOUBLE:
            printf("%lf\n", *((double*)valuePtr));
            break;
        case TFLOAT:
            printf("%f", *((float*)valuePtr));
            break;
        case TUINT8_T:
            printf("%hho\n", *((uint8_t*)valuePtr));
            break;
        case TUINT16_T:
            printf("%u\n", *((uint16_t*)valuePtr));
            break;
        case TUINT32_T:
            printf("%u\n", *((uint32_t*)valuePtr));
            break;
        case TUINT64_T:
            printf("%" PRIu64 "\n", *((uint64_t*)valuePtr));
            break;

    }
}

int main(){
    int num = 23;
    double dnum = 3.14;
    char symb = 'A';

    printValue(&num, TINT);
    printValue(&dnum, TDOUBLE);
    printValue(&symb, TCHAR);

    return 0;
}