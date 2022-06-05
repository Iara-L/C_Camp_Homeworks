#include <stdio.h>
#include <stdint.h>

void bin(unsigned n)
{
    unsigned i;
    int counter = 0;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    while (n) {
        n &= (n - 1), counter++;
    }
    printf("\nAttendance: %d", counter);
    printf("\nMissing: %d", 32 - counter);
}

int main(void) {
    uint32_t attendance = 0x00;
    int n;
    int option;

    while (1) {
        printf("\n1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        if (option == 1) {
            scanf("%d", &n);
            if (n >= 0 && n < 32) {
                attendance |= (1 << n);
            }
            else {
                fprintf(stderr, "\nInvalid value.");
                continue;
            }
        }
        else if (option == 2) {
            scanf("%d", &n);
            if (n >= 0 && n < 32) {
                attendance &= ~(1 << n);
            }
            else {
                fprintf(stderr, "\nInvalid value.");
                continue;
            }
        }
        else if (option == 3) {
            bin(attendance);
        }
        else if (option == 4) {
            if (n >= 0 && n < 32) {
                scanf("%d", &n);
                attendance ^= (1 << n);
            }
            else {
                fprintf(stderr, "\nInvalid value.");
                continue;
            }
        }
        else {
            fprintf(stderr, "\nError. Try again.");
            break;
        }
    }

    return 0;
}