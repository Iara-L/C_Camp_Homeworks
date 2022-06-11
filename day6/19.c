#include <stdio.h>
#include <stdarg.h>

unsigned bitsNcount(unsigned count, unsigned bitscnt, ...){
    int nums = 0;
    va_list args;
    va_start(args, count);

    for(int i = 0; i < count; i++){
        int temp = 0;
        unsigned int arg = va_arg(args, unsigned);
        while(arg){
            arg &= (arg - 1);
            temp++;
        }
        //printf("\n\t%d\n", temp);
        if(temp == bitscnt){
            nums++;
        }
    }
    va_end(args);

    return nums;
}

int main(){
    printf("%d\n", bitsNcount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%d\n", bitsNcount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%d\n", bitsNcount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111));

    return 0;
}