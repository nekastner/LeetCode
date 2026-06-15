int lengthOfLastWord(const char* s) {

    // define variables for loop and return
    int i = 0; // text index
    int c = 0; // counter for current word
    int c_last = 0; // counter for last word

    // find length of last word
    while (s[i] != '\0') { // iterate until string end

        // if not in word (which is a space), reset counter
        if (s[i] == ' ') {
            c = 0;
            i++;
            continue;
        }

        // count word length
        c++; // increment counter
        c_last = c; // save counter before possible reset in next reset
        i++;
    }

    return c_last;
}