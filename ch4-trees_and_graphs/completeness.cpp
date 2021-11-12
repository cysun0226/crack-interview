/**
* Leetcode 958
* https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/

class Solution {
public:
    struct Checker {
        int height;
        int count;
        Checker(int h, int c): height(h), count(c) {}
    };
    
    bool isCompleteTree(TreeNode* root) {
        return (check(root).height == -1)? false : true;
    }
    
    Checker check(TreeNode* root) {
        // skip the left node
        if (root->left == nullptr && root->right != nullptr)
            return Checker(-1, -1);
        
        // leaf
        if (root->left == nullptr && root->right == nullptr)
            return Checker(1, 1);
        
        int r_height, l_height, height, count;
        Checker l_check = check(root->left);
        Checker r_check = (root->right == nullptr)? Checker(0, 0) : check(root->right);
        
        if (l_check.height == -1 || r_check.height == -1)
            return Checker(-1, -1);
        
        // height diff > 1
        if (abs(l_check.height - r_check.height) > 1)
            return Checker(-1, -1);
        
        // #right > #left
        if (l_check.count < r_check.count)
            return Checker(-1, -1);
        
        // left is not full, then right should not have any node
        if (l_check.height == r_check.height && l_check.count % 2 == 0)
            return Checker(-1, -1);
        
        // right is not full, but the left keep growing
        if (r_check.count % 2 == 0 && r_check.count > ) {
            return Checker(-1, -1);
        }   
        
        height = (l_check.height > r_check.height)? l_check.height : r_check.height;
        height += 1;
        int r_count, l_count;
        r_count = (root->right == nullptr)? 0: r_check.count;
        l_count = (root->left == nullptr)? 0: l_check.count;
        
        count = l_count + r_count + 1;
        
        return Checker(height, count);
    }
    
    
};