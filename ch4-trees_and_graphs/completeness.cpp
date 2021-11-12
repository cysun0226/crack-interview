/**
* Leetcode 958
* https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

#include <iostream>
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
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        int node_count = count(root);
        
        return check(root, 0, node_count);
    }
    
    int count(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return count(root->left) + count(root->right) + 1;
    }
    
    bool check(TreeNode* root, int index, int count) {
        if (root == nullptr)
            return true;
        if (index >= count)
            return false;
        
        
        return (check(root->left, 2*index+1, count) && check(root->right, 2*index+2, count));
    }
};

int main() {
    vector<TreeNode> nodes;
    for (size_t i = 0; i < 6; i++){
        nodes.push_back(TreeNode());
    }

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[2].left = &nodes[5];

    Solution().isCompleteTree(&nodes[0]);

    return 0;
}