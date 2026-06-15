int lengthOfLastWord(const char* s) {

    int i = 0, c = 0, c_last = 0;

    while (s[i] != '\0') {

        if (s[i] == ' ') {
            c = 0;
            i++;
            continue;
        }

        c++;
        c_last = c;
        i++;
    }

    return c_last;
}