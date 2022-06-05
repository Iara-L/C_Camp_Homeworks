#include <stdio.h>

int main() {
    int a, b, c;
    int result;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    result = (a > b && a > c) ? a : (b > a && b > c) ? b : c;

    printf("%d", result);

    return 0;
}