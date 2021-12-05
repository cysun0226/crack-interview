/**
* Leetcode 230
* https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    vector<int> values;
    int k;

public:
    int kthSmallest(TreeNode* root, int k_in) {
        k = k_in;
        traverse(root);
        return values[k-1];
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        if (values.size() > k) return;
        
        traverse(root->left);
        values.push_back(root->val);
        traverse(root->right);
    }
};