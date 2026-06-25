#include <stdbool.h>

bool isPowerOfFour(int n) {

    // handle edge case
    if (n == 0) return false;

    // check if n is power of 4
    while (true) {
        if (n == 1) return true;
        if (n & 3) return false; // bit 1 or 2 from right is set -> not dividable by four
        n >>= 2; // divide n by four
    }
}