#include <stdbool.h>

bool isPowerOfTwo(int n) {
    // handle edge case
    if (n <= 0) return false;
    // check if n is power of four
    while (true) {
        if (n == 1) return true;
        if (n & 1) return false;
        n >>= 1;
    }
}