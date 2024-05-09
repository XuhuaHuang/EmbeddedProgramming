/**
 * @file print_linked_list.cpp
 * @author Xuhua Huang
 * @brief https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
 * @version 0.1
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the print_linked_list function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void print_linked_list(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }

}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    std::cin >> llist_count;
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        std::cin >> llist_item;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    print_linked_list(llist->head);

    return 0;
}
