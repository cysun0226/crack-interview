/*
* Leetcode 965. Univalued Binary Tree
* https://leetcode.com/problems/univalued-binary-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int uni_value;
    
public:
    bool isUnivalTree(TreeNode* root) {
        uni_value = root->val;
        return traverse(root);
    }
    
    bool traverse(TreeNode* root) {
        // reach the leaf
        if (root == nullptr)
            return true;
        
        // check the node value
        if (root->val != uni_value)
            return false;
        
        bool left_pass = traverse(root->left);
        bool right_pass = traverse(root->right); 
        
        return (left_pass && right_pass);
    }
};