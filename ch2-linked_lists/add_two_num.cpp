/**
* Leetcode 2
* https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *curr = new ListNode;
        ListNode *sum_head = curr;

        bool carry = false;
        while (ptr1 != nullptr || ptr2 != nullptr) {
            int v1 = (ptr1 == nullptr)? 0 : ptr1->val;
            int v2 = (ptr2 == nullptr)? 0 : ptr2->val;

            int sum_val = v1 + v2;
            if (carry) sum_val += 1;
            if (sum_val >= 10) {
                carry = true;
                sum_val -= 10;
            }
            else 
                carry = false;

            curr->val = sum_val;

            if (ptr1 != nullptr) ptr1 = ptr1->next;
            if (ptr2 != nullptr) ptr2 = ptr2->next;
            if (!(ptr1 == nullptr && ptr2 == nullptr)) {
                curr->next = new ListNode;
                curr = curr->next;
            }
        }

        // the last digit
        if (carry) {
            curr->next = new ListNode;
            curr->next->val = 1;
        }

        return sum_head;
    }
};