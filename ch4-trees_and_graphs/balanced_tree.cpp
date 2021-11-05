/**
* Given a binary tree, determine if it is height-balanced.
* https://leetcode.com/problems/balanced-binary-tree/
*/

#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
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
    bool is_balanced = true;

public:
    bool isBalanced(TreeNode* root) {
        countDepth(root);
        return is_balanced;
    }

    int countDepth(TreeNode* root) {
        // if (root->left == nullptr && root->right != nullptr) {
        if (root == nullptr) {
            return 0;
        }
        
        int depth_left = (root->left == nullptr)? 0 : countDepth(root->left);
        int depth_right = (root->right == nullptr)? 0 : countDepth(root->right);

        // check if balanced
        if (abs(depth_right - depth_left) > 1) {
            is_balanced = false;
            return 0;
        }

        return max(depth_left, depth_right) + 1;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;

        // determine the root
        int root_idx = (nums.size() % 2 == 0)? (nums.size()/2)-1 : nums.size()/2;
        TreeNode* root = new TreeNode(nums[root_idx]);
        
        // left
        std::vector<int> left_nums(&nums[0], &nums[root_idx]);
        root->left = sortedArrayToBST(left_nums);

        // right
        std::vector<int> right_nums(&nums[root_idx+1], &nums[nums.size()]);
        root->right = sortedArrayToBST(right_nums);

        return root;
    }
};

int main() {
    vector<int> input{-10, -7, -3, 0, 5, 8, 9};
    TreeNode* root = Solution().sortedArrayToBST(input);
    cout << Solution().isBalanced(root) << endl;

    return 0;
}