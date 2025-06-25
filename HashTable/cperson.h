/**
 * @file cperson.h
 * @author Xuhua Huang
 * @brief Define a C-style struct for a person.
 * @version 0.1
 * @date 2025-06-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef CPERSON_H
#define CPERSON_H

typedef struct CPerson {
    char name[100];
    int age;
} person_t;

extern person_t* DELETED_NODE; // Pointer to a deleted node, used in hash table operations

#endif // !CPERSON_H
