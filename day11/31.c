#include <stdio.h>

#define MAX(X, Y, Z) (a > b && a > c) ? a : (b > a && b > c) ? b : c
#define MIN(X, Y, Z) (a < b && a < c) ? a : (b < a && b < c) ? b : c
#define SETBIT(MASK, BIT) MASK |= (1 << BIT)
#define CLEARBIT(MASK, BIT) MASK &= ~(1 << BIT)
#define INVERSEBIT(MASK, BIT) MASK ^= (1 << BIT)
#define CHECKBIT(MASK, BIT) MASK & (1 << BIT)
#define SWAP(A, B) A ^= B ^= A ^= B

