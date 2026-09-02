int lengthOfLastWord(const char* s)
{
    int i = 0; // char index
    int c = 0; // counter for current word
    int c_last = 0; // counter of last word

    while (s[i] != '\0') // iterate until string end
    {
        // if not in word (which is a space), reset counter
        if (s[i] == ' ')
        {
            c = 0;
            i++;
            continue;
        }

        // count word length
        c++; // increment counter
        c_last = c; // save counter before possible reset in next iteration
        i++;
    }

    return c_last;
}