/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        
        TreeNode* prev = nullptr;
        TreeNode* current = root;
        stack<TreeNode*> s;
        
        while (!s.empty() || current != nullptr){
            while(current != nullptr){
                s.push(current);
                current = current -> left;
            }
            
            current = s.top();
            s.pop();
            if (prev != nullptr && prev -> val >= current -> val){
                return false;
            }
            
            prev = current;
            current = current -> right;
        }
        return true;
    }
};