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
    ListNode *getIntersectionNode_bf(ListNode *headA, ListNode *headB) {
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB, *intersect = nullptr;
        
        // count the length of two lists
        int lenA = 0, lenB = 0;
        while (ptrA != nullptr) lenA++;
        while (ptrB != nullptr) lenB++;

        ptrA = headA, ptrB = headB;

        // skip the non-intersect nodes
        if (lenA >= lenB) {
            int skip = lenA - lenB;
            while (skip > 0) {
                ptrA = ptrA->next;
                skip--;
            }
        }
        else {
            int skip = lenB - lenA;
            while (skip > 0) {
                ptrB = ptrB->next;
                skip--;
            }
        }

        // find the starting point of the intersection
        while (ptrA != nullptr) {
            if (ptrB == ptrA) {
                intersect = ptrB;
                break;
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return intersect;
    }

};