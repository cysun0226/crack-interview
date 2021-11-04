/**
* https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
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
public:
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

    void printTree(TreeNode* root){
        if (root->left != nullptr) {
            printTree(root->left);
        }
        
        cout << root->val << endl;

        if (root->right != nullptr) {
            printTree(root->right);
        }
    }
};

int main() {
    vector<int> input{-10, -7, -3, 0, 5, 8, 9};
    TreeNode* root = Solution().sortedArrayToBST(input);
    Solution().printTree(root);

    return 0;
}
 
