/**
 * @file cperson.c
 * @author Xuhua Huang
 * @brief Implementation of functions for the CPerson struct.
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "cperson.h"
#include <stdlib.h>
#include <string.h>

person_t* DELETED_NODE = (person_t*)(0xFFFFFFFF); // Unsafe, but illustrative

person_t* create_person(const char* name, int age) {
    person_t* new_person = (person_t*)malloc(sizeof(person_t));
    if (new_person) {
        strncpy(new_person->name, name, sizeof(new_person->name) - 1);
        new_person->name[sizeof(new_person->name) - 1] = '\0';
        new_person->age = age;
    }
    return new_person;
}

void delete_person(person_t* person) {
    if (person) {
        free(person);
    }
}
