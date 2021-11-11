/**
* Leetcode 237
* https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nxt = node->next;
        // get the value & *next of the next node
        node->val = nxt->val;
        node->next = nxt->next;
        delete nxt;
    }
};
