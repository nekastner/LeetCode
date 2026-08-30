#include <stdbool.h>
#include <stdint.h>
#include <math.h>

static bool isPalindrome(int x)
{
    if (x < 0) return false; // negative integers can not be palindromes
    if (x < 10) return true; // all integers of length 1 are palindromes

    // TODO: without array
    uint8_t decimal_places[10]; // buffer for each decimal place (2^31 - 1 = 2147483647 -> 10 digits max)
    for (int i = 0; i < 10; i++) decimal_places[i] = 0; // set all places in buffer to 0

    // load x into array of decimal places
    int power = (int)pow(10, 10);
    for (int i = 9; i >= 0; i--)
    {
        power /= 10; // calculate power for current decimal place
        if (power > x) continue; // if the power is too small, skip to next decimal place
        decimal_places[i] = (uint8_t) (x / power); // calculate decimal place and load it into array for decimal places
        x -= decimal_places[i] * power; // subtract the decimal place from x
    }

    int i_a = 0, i_b = 9; //  indexes for head and tail digits of x
    for (; i_b >= 2; i_b--) if (decimal_places[i_b] != 0) break; // set tail index to last value that is not 0

    while (true)
    {
        if (i_a >= i_b) return true; // if both indexes reached each other, it must be a palindrome
        if (decimal_places[i_a] != decimal_places[i_b]) return false; // if the values at i_a and i_b are not equal, it is no palindrome
        i_a++; i_b--; // move the indexes towards each other
    }
}