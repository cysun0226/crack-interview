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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = head->next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

int main() {
    // create the input linked list
    std::vector<int> input1{1, 2, 3, 4, 5};
    std::vector<int> input2{1, 2, 3, 4, 5, 6};

    ListNode* list1 = new ListNode;
    ListNode* list2 = new ListNode;
    initList(input1, list1);
    initList(input2, list2);
    
    
    std::cout << "Linked list 1" << std::endl;
    printList(list1);
    ListNode* last = Solution().reverseList(list1);
    printList(last);

    std::cout << "\nLinked list 2" << std::endl;
    printList(list2);
    last = Solution().reverseList(list2);
    printList(last);

    return 0;
}