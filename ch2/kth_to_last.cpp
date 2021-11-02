#include "list_node.h"

// ListNode* reverseList(ListNode* head) {
//     ListNode* rev_head, *prev = NULL, *curr = head, *next = NULL;
//     while (curr != NULL){
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     rev_head = prev;

//     return rev_head;
// }

ListNode* kthToLast(ListNode* head, int k){

    // reverse the linked list
    auto reverseList = [](ListNode* head){ 
        ListNode* rev_head, *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        rev_head = prev;

        return rev_head;
    };

    ListNode* rev_head = reverseList(head);

    // iterate to the given index
    ListNode* kth = rev_head;
    for (size_t i = 0; i < k-1; i++){
        kth = kth->next;
    }

    return kth;
}

int main() {
    // create the input linked list
    std::vector<int> input1{1, 2, 3, 4, 3, 5, 2, 8, 9, 10 };
    std::vector<int> input2{1, 2, 3, 4, 5, 6};

    ListNode* list1 = new ListNode;
    ListNode* list2 = new ListNode;
    initList(input1, list1);
    initList(input2, list2);
    
    
    std::cout << "Linked list 1" << std::endl;
    printList(list1);
    ListNode* last = kthToLast(list1, 3);
    std::cout << "(-" << 3 << ") = " << last->data << std::endl;

    std::cout << "\nLinked list 2" << std::endl;
    printList(list2);
    last = kthToLast(list2, 2);
    std::cout << "(-" << 2 << ") = " << last->data << std::endl;

    // delete the list
    deleteList(list1);
    deleteList(list2);

    return 0;
}