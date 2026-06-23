#include <stdbool.h>

bool isPowerOfTwo(const int n) {

    // filter edge cases
    if (n <= 0) {
        return false;
    }

    // actually check condition
    int n_rest = n;
    while (true) {
        if (n_rest == 1) return true;
        if (n_rest % 2 != 0) return false;
        n_rest >>= 1;
    }
}