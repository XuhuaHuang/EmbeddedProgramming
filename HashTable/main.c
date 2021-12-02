/**
 * @file hashTable.c
 * @author Xuhua Huang (xuhuahuang0412@gmail.com)
 * @brief Understanding and implementing a hash table in C.
 * Constant operation time of O(1) with Open Addressing and External Chamber.
 * To run the file on Windows with MinGW:
 * $ mingw32-make
 * $./hashtable
 * 
 * @version 0.1
 * @date 2021-11-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (CPerson*)(0xFFFFFFFFFFFFFFFFUL)
/* UL at the end of the hex address for DELETED_NODE means 'unsigned long'. */

/**
 * @brief Define a C-style struct
 * and name it `CPerson` 
 */
typedef struct {
    char name[MAX_NAME];
    int age;
} CPerson;

/**
 * @brief Create hash function.
 * @return unsigned int 
 */
unsigned int hash(const char* const name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;                            /* variable to store the sum of ASCII codes */
    for(int i = 0; i < length; ++i) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;   /* make sure the value fits in the table */
    }

    return hash_value;
}

CPerson* hash_table[TABLE_SIZE];

/**
 * @brief Define a function to initialize the hash table.
 * @return void
 */
void init_hash_table() {
    /* global array of CPerson* is visiable in this function. */
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hash_table[i] = NULL;
    }
    /* table is empty. */
    return;
}

/**
 * @brief Define a function to print elements in the hash table.
 * @return void
 */
void print_table() {
    printf("\nStart %s\n", __FUNCTION__);
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);

        }
        else{
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End %s\n", __FUNCTION__);
    return;
}

/**
 * @brief Define a function to insert a person in the table.
 * 
 * @param ptr 
 * @return bool -> either the operation was successful or not
 */
bool insert_to_table(CPerson* ptr) {
    /* verify pointer is not NULL. */
    if (ptr == NULL) {
        return false;
    }
    int index = hash(ptr->name);
    /* check for slot availability. */
    for (int i = 0; i < TABLE_SIZE; ++i) {
        int try_to_locate = (i + index) % TABLE_SIZE;   /* best case: person is allocated when i=0*/
        if (hash_table[try_to_locate] == NULL) {
            hash_table[try_to_locate] = ptr;
            return true;
        }
    }
    
    return false;
}

/**
 * @brief Define a function to look up a person by name in the table.
 * 
 * @param name 
 * @return CPerson* 
 */
CPerson* hash_table_lookup(const char* const name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; ++i) {
        int try_to_locate = (i + index) % TABLE_SIZE;   /* best case: result is found when i=0. */
        if (hash_table[try_to_locate] == NULL) {
            return NULL;
        }
        if (hash_table[try_to_locate] == DELETED_NODE) {
            continue;
        }
        if (strncmp(hash_table[try_to_locate]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try_to_locate];
        }
    }
    return NULL;
}

/**
 * @brief Delete a person from the table by its looking up the name.
 * 
 * @param constant string name 
 * @return CPerson* 
 */
CPerson* del_from_table(const char* const name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; ++i) {
        int try_to_locate = (i + index) % TABLE_SIZE;       /* best case: result is found when i=0. */
        if (hash_table[try_to_locate] == NULL) {            /* indexed slot is empty. */
            return NULL;
        } 
        if (hash_table[try_to_locate] == DELETED_NODE) {    /* indexed slot has been deleted. */
            continue;
        }
        if(strncmp(hash_table[try_to_locate]->name, name, TABLE_SIZE) == 0) {
            
            CPerson* temp = hash_table[try_to_locate];
            hash_table[try_to_locate] = DELETED_NODE;
            return temp;
        }
    }
    return NULL;
}

int main(void) {
    init_hash_table();
    print_table();  /* expecting empty hash table. */
    
    /* create multiple Cperson object with list initialization. */
    CPerson jacob = {.name="Jacob", .age=40};
    CPerson andy = {.name="Andy", .age=20};
    CPerson liam = {.name="Liam", .age=34};

    /* insert people to the hash table. */
    insert_to_table(&jacob);
    insert_to_table(&andy);
    insert_to_table(&liam);
    print_table();

    /* look up a person in the table by name. */
    CPerson* temp = hash_table_lookup("Jacob");
    if (temp == NULL) {
        printf("Jacob is not found in the hash table!\n");
    } else {
        printf("Found %s at index %i\n", temp->name, hash(temp->name));
    }

    /* delete jacob from the table and verify the result. */
    del_from_table("Jacob");
    print_table();

    system("pause");
    return 0;
}