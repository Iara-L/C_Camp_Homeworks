#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask);

int main(){
    int counter = 0;
    unsigned mask64 = 5;

    counter = onesCount(mask64);

    printf("\n%d\n", counter);

    return 0;
}

unsigned onesCount(uint64_t mask){
    int counter = 0;
    
    while (mask) {
        mask &= (mask - 1), counter++;
    }
    return counter;
}