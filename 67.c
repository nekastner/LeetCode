#include <stdlib.h>
#include <string.h>

// TODO: review

char* addBinary(const char* a, const char* b) {
    const size_t a_len = strlen(a);
    const size_t b_len = strlen(b);
    const size_t c_len = (a_len >= b_len ? a_len : b_len) + 1;
    char* c = malloc(c_len+1);
    c[c_len] = '\0';
    unsigned char transfer = 0; // var to save transfer in calculation
    for (int i = 0; i < c_len; i++) {
        // calc indexes for a and b from behind
        const int a_i = (int)a_len - 1 - i;
        const int b_i = (int)b_len - 1 - i;
        const int c_i = (int)c_len - 1 - i;
        // get values
        const unsigned char a_val = (a_i >= 0) ? a[a_i] - '0' : 0;
        const unsigned char b_val = (b_i >= 0) ? b[b_i] - '0' : 0;
        // calc
        const unsigned char sum = a_val + b_val + transfer;
        transfer = sum / 2;
        c[c_i] = (char)((sum % 2) + '0');
    }
    // check start of actual value
    int start_index = 0;
    for (int i = 0; i < c_len - 1; i++) { // leave at least one 0, to not remove the whole result
        if (c[i] != '0') break;
        start_index++;
    }
    memmove(c, c + start_index, strlen(c + start_index) + 1);
    // return result
    return c;
}
