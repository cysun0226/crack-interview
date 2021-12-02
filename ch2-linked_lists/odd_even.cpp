/**
* Leetcode 328
* https://leetcode.com/problems/odd-even-linked-list/
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* curr = head, *prev;
        ListNode* even_head = new ListNode;
        ListNode* even = even_head;

        while (curr != nullptr) {
            ListNode* next_odd = (curr->next != nullptr)? curr->next->next : nullptr;
            even->next = curr->next;
            even = curr->next;

            curr->next = next_odd;
            prev = curr;
            curr = next_odd;
        }

        // concat the even list
        prev->next = even_head->next;

        return head;
    }
};