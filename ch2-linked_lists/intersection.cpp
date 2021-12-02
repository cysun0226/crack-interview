/**
* Leetcode 160
* https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB, *intersect = nullptr;
        while (ptrA != nullptr && intersect == nullptr) {
            ptrB = headB;
            while (ptrB != nullptr) {
                if (ptrB == ptrA) {
                    intersect = ptrB;
                    break;
                }
                ptrB = ptrB->next;
            }
            ptrA = ptrA->next;
        }

        return intersect;
    }
};