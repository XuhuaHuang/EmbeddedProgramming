/**
 * @file hash_table.c
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-25
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "hash_table.h"

#include <stdio.h>
#include <string.h>

static person_t* hash_table[HASH_TABLE_SIZE];

unsigned int hash(const char* const name) {
    int length = strnlen(name, MAX_NAME_LENGTH);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; ++i) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % HASH_TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        hash_table[i] = NULL;
    }
}

bool insert_to_table(const person_t* const ptr) {
    if (!ptr) return false;
    int index = hash(ptr->name);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int try_index = (i + index) % HASH_TABLE_SIZE;
        if (hash_table[try_index] == NULL) {
            hash_table[try_index] = (person_t*)ptr;
            return true;
        }
    }
    return false;
}

person_t* hash_table_lookup(const char* const name) {
    int index = hash(name);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int try_index = (i + index) % HASH_TABLE_SIZE;
        if (hash_table[try_index] == NULL) return NULL;
        if (hash_table[try_index] == DELETED_NODE) continue;
        if (strncmp(hash_table[try_index]->name, name, MAX_NAME_LENGTH) == 0) {
            return hash_table[try_index];
        }
    }
    return NULL;
}

person_t* del_from_table(const char* const name) {
    int index = hash(name);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int try_index = (i + index) % HASH_TABLE_SIZE;
        if (hash_table[try_index] == NULL) return NULL;
        if (hash_table[try_index] == DELETED_NODE) continue;
        if (strncmp(hash_table[try_index]->name, name, MAX_NAME_LENGTH) == 0) {
            person_t* temp = hash_table[try_index];
            hash_table[try_index] = DELETED_NODE;
            return temp;
        }
    }
    return NULL;
}

void print_table() {
    printf("\nStart %s\n", __FUNCTION__);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End %s\n", __FUNCTION__);
}
