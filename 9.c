#include <stdbool.h>

// TODO: review

int pow_of_10(const int exp) {
    int val = 1;
    for (int i = 0; i < exp; i++) val *= 10;
    return val;
}

bool isPalindrome(int x) {

    // negative integers can not be palindromes
    if (x < 0) return false;

    // all integers of length 1 are palindromes
    if (x < 10) return true;

    // buffer for each decimal place
    char broken_down[10];

    // set all places in buffer to 0
    for (int i = 0; i < 10; i++) broken_down[i] = 0;

    // load x into buffer
    for (int i = 9; i >= 0; i--) {

        // calculate power for current decimal place
        const int pow = pow_of_10(i);

        // if the power is too small, skip to next decimal place
        if (pow > x) continue;

        // calc decimal place
        const char dec_plc = (char) (x / pow);

        // load decimal place into buffer
        broken_down[i] = dec_plc;

        // subtract the power from x
        x -= dec_plc * pow;
    }

    // define indexes for head and tail of buffer
    int i_a = 0, i_b = 9;

    // set tail index to last value that is not 0
    for (; i_b >= 2; i_b--) { // because then i_a and i_b are directly beside each other
        if (broken_down[i_b] != 0) break;
    }

    while (true) {

        // if both indexes reached each other, it must be a palindrome
        if (i_a >= i_b) return true;

        // if the values at i_a and i_b are not equal, it is no palindrome
        if (broken_down[i_a] != broken_down[i_b]) return false;

        // move the indexes towards each other
        i_a++;
        i_b--;
    }
}
