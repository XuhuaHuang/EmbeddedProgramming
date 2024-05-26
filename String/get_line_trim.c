/**
 * @file getline_trim.c
 * @author Xuhua Huang
 * @brief Attempt to implement getLine and trim in C with realloc().
 * @version 0.1
 * @date 2022-11-24
 *
 * $ gcc -c ./getline_trim.c -o getline_trim.exe
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <cassert>

char* get_line(void) {
    const size_t sizeIncrement = 10;
    char* buffer = malloc(sizeIncrement);
    char* currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;

    // determine whether the buffer allocation was successful
    if (currentPosition == NULL) {
        return NULL;
    }

    while(1) {
        character = fgetc(stdin);
        if (character == '\n') {
            break;
        }
        // allocate more memory by incrementing predetermined increment size
        if (++length >= maximumLength) {
            char* newBuffer = realloc(buffer, maximumLength += sizeIncrement);
            // determine the re-allocation was successful
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition += character;
    }
    // assign terminate character at the end for the string to be parsed properly
    *currentPosition = '\0';
    return buffer;
}

char* trim(char* phrase) {
    char* old = phrase;
    // prevent naming the newPhrase variable "new"
    // to avoid mixing keyword with C++
    char* newPhrase = phrase;
    // keep iterating the pointer until the character is not a space
    // skips the spaces padded to the beginning of a string
    while (*old == ' ') {
        old++;
    }
    // keep copying the content of the old string to the new one
    // until the end of the old string (terminate/null character)
    while (*old) {
        *(newPhrase++) = *(old++);
    }
    // append the null character to the end of the new string
    *newPhrase = 0;
    return (char*)realloc(phrase, strlen(phrase) + 1);
}

int main(void) {
    char* buffer = (char*)malloc(strlen(" cat") + 1);
    cassert (buffer != NULL);
    strcpy_s(buffer, strlen(" cat") + 1, " cat");
    printf("%s\n", trim(buffer));

    return 0;
}
