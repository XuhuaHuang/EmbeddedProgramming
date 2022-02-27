/*****************************************************************//**
 * \file   log.h
 * \brief  Custom LOG() macro to print location of the function call
 * with __VA_ARGS__ and fprintf() in C.
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#ifndef LOG_H
#define LOG_H

#ifndef _STDIO_H
#include <stdio.h>
#else

/* Global Macro Definition */
#define LOG(...) {\
    fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

#endif