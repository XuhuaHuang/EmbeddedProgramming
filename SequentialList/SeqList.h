#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>

#define LISTSIZE 100

typedef struct
{
    int list[LISTSIZE];
    int length;
} SeqList;

/* Function to initialize sequential lists. */
void InitList(SeqList* L) {
    L->length = 0;
}

/* Function to determine whether the list is empty. */
bool isListEmpty(const SeqList& L) {
    if (!L.length)
        return true;
    else
        return false;
}

/* Function to get element by index and existing pointer. */
int GetElement(const SeqList& L, int i, int* e) {
    if (i<1 || i>L.length) // determine the boundary edge cases
        return -1;

    *e = L.list[i - 1];
    return 1;
}

/* Function to get element by content, O(n). */
int LocElement(const SeqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.list[i] == e)
            return i + 1;
    }
    return 0;
}

/* Function to insert an element to the list. */
/* return -1 for error, 0 for full list, 1 for success. */
int InsertElement(SeqList* L, int i, int e) {
    if (i<1 || i>L->length + 1) {
        printf_s("Illegal index, out of list boundary.\n");
        return -1;
    }
    else if (L->length >= LISTSIZE) {
        printf_s("Sequential list is full.\n");
        return 0;
    }
    else {
        for (int j = L->length; j >= i; j--)
            L->list[j] = L->list[j - 1];
        L->list[i - 1] = e;
        L->length++;
        return 1;
    }
}

/* Function to delete an element from the list. */
int DeleteElement(SeqList* L, int i, int* e) {
    if (L->length <= 0) {
        printf_s("Sequential list is empty to begin with!\n");
        return 0;
    }
    else if (i<1 || i>L->length) {
        printf_s("Illegal index, out of list boundary.\n");
        return -1;
    }
    else {
        *e = L->list[i - 1];
        for (int j = i; j <= L->length - 1; j++)
            L->list[j - 1] = L->list[j];
        L->length--;
        return 1;
    }
}

/* Function to determine the length of a list. */
int ListLength(const SeqList& L) {
    return L.length;
}

/* Function to clear a list. */
void ClearList(SeqList* L) {
    L->list[LISTSIZE - 1] = {};
    L->length = 0;
}

#endif
