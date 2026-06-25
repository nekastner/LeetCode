#include <stdbool.h>

bool isPowerOfThree(const int n) {

    // handle edge case
    if (n == 0) return false;

    // check if n is power of 3
    int n_rest = n;
    while (true) {
        if (n_rest == 1) return true;
        if (n_rest % 3 != 0) return false;
        n_rest /= 3;
    }
}