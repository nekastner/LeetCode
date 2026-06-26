double myPow(double x, long n) {

    // handle edge cases
    if (n == 0 || x == 1) return 1;
    if (x == -1) return !(n & 1) ? 1 : -1; // checks whether n is even or odd

    // convert values if n is negative
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    /* calc x^n with O(log(N))
     * example: y = x^13 = x^8 * x^4 * x^1 (bit 2 from right is not set)
     */
    double y = 1;
    for (; n > 0; n >>= 1) { // while n has bits
        if (n & 1) y *= x; // only multiply if bit is set
        x *= x; // increase go to next bit
    }
    return y;
}