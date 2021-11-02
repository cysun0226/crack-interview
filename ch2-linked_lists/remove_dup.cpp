/**
* Write code to remove duplicates from an unsorted linked list. 
* FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? 
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// Definition of Singly Linked List
struct ListNode {
    int data;
    ListNode *next;
    ListNode() {data = 0; next = NULL;}
    ListNode(int x) {data = x; next = NULL;}
    ListNode(int x, ListNode *nx) {data = x; next = nx;}
};

ListNode* removeDups(ListNode* head){
    // use a map to record existing values
    std::unordered_map<int, int> count;
    
    // iterate the linked list
    ListNode* current = head;
    ListNode* prev = NULL;
    while(true){
        // check if the value exists
        if (count.find(current->data) == count.end()) {
            // not exist
            count[current->data] = 1;
            prev = current;
            current = current->next;
        }
        else {
            // duplicate, remove the node from the linked list
            prev->next = current->next; // update the previous `next` to the next node
            ListNode* tmp = current;
            current = current->next;
            delete tmp;
        }

        if ( current == NULL ){
            break;
        }
    }

    return head;
}

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

int main() {
    // create the input linked list
    std::vector<int> input1{1, 2, 3, 4, 3, 5, 2, 8, 9, 10};
    std::vector<int> input2{1, 2, 3, 4, 5, 6};

    ListNode* list1 = new ListNode;
    ListNode* list2 = new ListNode;
    initList(input1, list1);
    initList(input2, list2);
    
    // remove duplicates and print the result
    std::cout << "Linked list 1" << std::endl;
    printList(list1);
    std::cout << "Linked list 1 (removeDups)" << std::endl;
    list1 = removeDups(list1);
    printList(list1);

    std::cout << "\nLinked list 2" << std::endl;
    printList(list2);
    std::cout << "Linked list 2 (removeDups)" << std::endl;
    list2 = removeDups(list2);
    printList(list2);


    // delete the list
    deleteList(list1);
    deleteList(list2);

    return 0;
}


