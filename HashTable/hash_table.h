/**
 * @file hash_table.h
 * @author Xuhua Huang
 * @brief Practice of hash table in C++23 after lecture of Data Structures and Algorithms.
 * Constant operation time of O(1) with Open Addressing and External Chamber.
 *
 * @version 0.1
 * @date 2025-06-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "cperson.h"
#include <stdbool.h>

#define HASH_TABLE_SIZE 10
#define MAX_NAME_LENGTH 100

typedef struct HashTableEntry {
    person_t person;
    bool isOccupied; // Flag to check if the entry is occupied
} hash_table_entry_t;

unsigned int hash(const char* const name);
void init_hash_table();
bool insert_to_table(const person_t* const ptr);
person_t* hash_table_lookup(const char* const name);
person_t* del_from_table(const char* const name);
void print_table();

#endif // !HASH_TABLE_H
