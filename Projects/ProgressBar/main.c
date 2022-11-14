/**
 * @file main.c
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief A preliminary updating progress bar in CLI written in C
 * To run the file on Windows with MinGW:
 * $ mingw32-make
 * $./progbar
 * 
 * @version 0.1
 * @date 2021-11-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

/**
 * @brief Sleep for usec micro-seconds.
 * Compensating for unistd.h on POSIX.
 * namespace does not exist in C, therefore has util_ prefix
 * @param usec 
 */
void util_usleep(__int64 usec) { 
    HANDLE timer; 
    LARGE_INTEGER ft; 

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL); 
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
    WaitForSingleObject(timer, INFINITE); 
    CloseHandle(timer); 
}

const int _PROG_BAR_LENGTH = 30; // define a 30 character long progree bar

void update_bar(const int percent_done) {
    int num_chars = percent_done * _PROG_BAR_LENGTH / 100;
    
    printf_s("\r["); // indicate the start of the progress bar
    for(int i = 0; i < num_chars; ++i) {
        printf_s("#");
    }
    for(int i = 0; i < _PROG_BAR_LENGTH - num_chars; ++i) {
        printf_s(" ");
    }
    fflush(stdout); // forecefully flush the output buffer to terminal
    printf_s("] %d%% Done", percent_done); // close the progress bar

    return;
}


int main(void) {
    printf_s("Hello, world!\n");

    for(int i = 0; i <= 100; ++i) {
        update_bar(i);
        util_usleep(2000);
    }
    printf("\n");

    system("pause");
    return 0;    
}