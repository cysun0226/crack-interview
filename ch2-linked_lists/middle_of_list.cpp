/**
* Leetcode 876
* https://leetcode.com/problems/middle-of-the-linked-list/
*/ 

#include "list_node.h"

#include <iostream>
#include <vector>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *curr = head;

        while (curr != nullptr){
            curr = curr->next;
            count++;
        }
        
        curr = head;
        for (size_t i = 0; i < count/2; i++) {
            curr = curr->next;
        }
        
        return curr;
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
    ListNode* middle = Solution().middleNode(list1);
    printList(middle);

    std::cout << "\nLinked list 2" << std::endl;
    printList(list2);
    middle = Solution().middleNode(list2);
    printList(middle);

    // delete the list
    deleteList(list1);
    deleteList(list2);
}