#include <stdbool.h>
#include <math.h>

static bool isPalindrome(const int x)
{
    if (x < 0) return false; // negative integers can not be palindromes
    if (x < 10) return true; // all decimal numbers of length 1 are palindromes

    int power_low = 1; // lowest power of 10 we need
    int power_high = (int)pow(10, 9); // highest power of 10 possible for (2^31 - 1)
    while (power_high > x) power_high /= 10; // find highest power we need for x

    // compare decimal digits
    while (1)
    {
        if (power_low >= power_high) return true;
        if (x / power_low % 10 != x / power_high % 10) return false;
        power_low *= 10;
        power_high /= 10;
    }
}