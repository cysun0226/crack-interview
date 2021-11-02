#ifndef LIST_NODE_H
#define LIST_NODE_H


#include <iostream>
#include <vector>

// Definition of Singly Linked List
struct ListNode {
    int data;
    ListNode *next;
    ListNode() {data = 0; next = NULL;}
    ListNode(int x) {data = x; next = NULL;}
    ListNode(int x, ListNode *nx) {data = x; next = nx;}
};

void printList(ListNode* head);

void deleteList(ListNode* head);

void initList(std::vector<int> input, ListNode* list);

#endif