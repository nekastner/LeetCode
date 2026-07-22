#include <stdlib.h>

int count_letters_on_key(const char key) {
    if (key == '7' || key == '9') return 4;
    return 3;
}

char** letterCombinations(const char* const digits, const int* const returnSize) {

    char char_a = 'a';
    char char_2 = '2';

    char** results = malloc(*returnSize);

    // TODO: solve
}