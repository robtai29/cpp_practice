/******************************************************************************
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

1.22.2022
*******************************************************************************/

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
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr){
            return -1;
        }
        
        TreeNode* current = root;
        stack<TreeNode*> s;
        
        while(!s.empty() || current != nullptr){
            while(current != nullptr){
                s.push(current);
                current = current -> left;
            }
            
            current = s.top();
            s.pop();
            k--;
            if (k == 0){
                return current -> val;
            }
            current = current -> right;
        }
        return -1;
    }
};

/*
class Solution {
private:
    void kthSmallest(TreeNode* node, int& k, int& val){
        if (node == nullptr){
            return;
        }
        
        kthSmallest(node -> left, k, val);
        k--;
        
        if (k == 0){
            val = node -> val;
            return;
        }
        kthSmallest(node -> right, k, val);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        kthSmallest(root, k, result);
        return result;
        
    }
};
*/