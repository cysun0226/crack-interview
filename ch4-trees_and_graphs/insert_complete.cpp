/**
* Leetcode 919
* https://leetcode.com/problems/complete-binary-tree-inserter/
*/

class CBTInserter {
private:
    TreeNode* root;
    
public:
    CBTInserter(TreeNode* r) {
        root = r;
    }
    
    int insert(int val) {
        // BFS to find the first empty spot
        queue<pair<TreeNode*, TreeNode*> > q; // <node, parent>
        q.push(make_pair(root, nullptr));
        
        while(!q.empty()) {
            TreeNode *n = q.front().first;
            TreeNode *parent = q.front().second;
            q.pop();
            
            if (n != nullptr) {
                q.push(make_pair(n->left, n));
                q.push(make_pair(n->right, n));
            }
            // empty spot, insert the node
            else {
                TreeNode* new_node = new TreeNode;
                new_node->val = val;
                if (parent->left == nullptr)
                    parent->left = new_node;
                else
                    parent->right = new_node;
                
                return parent->val;    
            }
        }
        
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};