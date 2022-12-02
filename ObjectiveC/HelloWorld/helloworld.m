/*****************************************************************//**
 * \file   helloworld.m
 * \brief  Hello world program in Objective-C.
 * 
 * \author Xuhua Huang
 * \date   October 18, 2021
 *********************************************************************/

#include <Foundation/Foundation.h>

int main(void) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    NSLog(@"Hello World!");
    [pool drain];

    return 0;
}
