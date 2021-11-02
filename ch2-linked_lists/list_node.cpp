#include "list_node.h"

void printList(ListNode* head) {
    ListNode* current = head;
    while(true){
        std::cout << current->data << " ";
        current = current->next;
        if ( current == NULL ){
            break;
        }
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head){
    ListNode* cur_node = head;
    while(true){
        ListNode* tmp = cur_node;
        cur_node = cur_node->next;
        delete tmp;

        if ( cur_node == NULL ){
            break;
        }
        
    }
}

void initList(std::vector<int> input, ListNode* list) {
    ListNode* cur_node = list;
    for (size_t i = 0; i < input.size(); i++){
        cur_node->data = input[i];

        if (i == input.size() -1) break;
        ListNode* new_node = new ListNode;
        cur_node->next = new_node;
        cur_node = new_node;
    }
}