/**
* Leetcode 222
* https://leetcode.com/problems/count-complete-tree-nodes/
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return count(root);
    }
    
    int count(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        int l_count, r_count;
        l_count = (root->left == nullptr)? 0 : count(root->left);
        r_count = (root->right == nullptr)? 0 : count(root->right);
        
        return l_count + r_count + 1;
    }
};