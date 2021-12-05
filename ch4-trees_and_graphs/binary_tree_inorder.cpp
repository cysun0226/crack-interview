/**
* Leetcode 94
* https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

#include <vector>

using namespace std;

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
    vector<int> nodes;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return nodes;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        
        traverse(root->left);
        nodes.push_back(root->val);
        traverse(root->right);
    }
};
