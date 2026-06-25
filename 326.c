#include <stdbool.h>

bool isPowerOfThree(int n) {
    // handle edge case
    if (n == 0) return false;
    // check if n is power of 3
    while (true) {
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        n /= 3;
    }
}