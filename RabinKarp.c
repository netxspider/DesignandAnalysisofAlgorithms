#include <stdio.h>
#include <string.h>

int rabin_karp(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int d = 256; // number of characters in the input alphabet
    int q = 101; // a prime number
    int h = 1;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int i, j;

    // The value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                return i;
        }
        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
    return -1;
}