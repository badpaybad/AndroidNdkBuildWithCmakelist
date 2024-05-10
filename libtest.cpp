
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include <ctype.h>

#include <string.h>
#include <stdlib.h>

#include<time.h>

#include <stdint.h>

#include <iostream>
#include <cstdio>
#include <istream>



extern "C" __attribute__((visibility("default"))) __attribute__((used))

char *dunp_test_stdString(char *text)
{
    size_t sizeA = strlen(text);
    char *b = " PONG ";
    size_t sizeB = strlen(b);
    size_t size = sizeof(char) * (sizeA + sizeB + 1); // Size of our new memory block large enough to contain both a and b.
                                                      // Leave additional space for null terminator
    char *c = (char *)malloc(size);

    memcpy(c, text, sizeA);      // Copy a into the first half of c
    memcpy(c + sizeA, b, sizeB); // Copy b into the second half
    c[sizeA + sizeB] = '\0';     // Assign null terminator to last character
    // free(c);
    return c;
}